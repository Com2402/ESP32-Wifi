#include "CYD28_audio.h"
#include "ui_files/ui.h"
#include "Config.h"
#include "SPIFFS.h"

TaskHandle_t audioTaskHandler;
#ifdef USE_MODULE_I2S
Audio audio;
#else
Audio audio(true, I2S_DAC_CHANNEL_LEFT_EN);
#endif

void audioTask(void *parameter);
void CreateQueues();

//****************************************************************************************
//                                   A U D I O _ T A S K                                 *
//****************************************************************************************
audioMessage_t audioTxMessage, audioRxMessage;

QueueHandle_t audioSetQueue = NULL;
QueueHandle_t audioGetQueue = NULL;
// ---------------------------------------------------------------
void CreateQueues()
{
	audioSetQueue = xQueueCreate(10, sizeof(audioMessage_t));
	audioGetQueue = xQueueCreate(10, sizeof(audioMessage_t));
}
// ---------------------------------------------------------------
void audioInit()
{

	log_i("freeheap %d ", ESP.getFreeHeap());
	xTaskCreatePinnedToCore(
		audioTask,			   /* Function to implement the task */
		"audioplay",		   /* Name of the task */
		1024 * 4,			   /* Stack size in words */
		NULL,				   /* Task input parameter */
		2 | portPRIVILEGE_BIT, /* Priority of the task */
		&audioTaskHandler,	   /* Task handle. */
		0					   /* Core where the task should run */
	);
}
// ---------------------------------------------------------------
void audioTask(void *parameter)
{
	log_i("Start audio task");
	CreateQueues();
	if (!audioSetQueue || !audioGetQueue)
	{
		log_e("queues are not initialized");
		while (true)
		{
			vTaskDelay(10);
		}
	}
	audioMessage_t audioRxTaskMessage;
	audioMessage_t audioTxTaskMessage;
#ifdef USE_MODULE_I2S
	// Setup I2S
	audio.setPinout(I2S_BCLK, I2S_LRC, I2S_DOUT);
#endif
	uint32_t vol = (config.volume_lv * 21) / 100;

	audio.setVolume(vol); // 0...21
	// audio.connecttoFS(SPIFFS, "/SamplesMP3/WelcomeVoice.mp3");

	while (true)
	{
		yield();
		if (xQueueReceive(audioSetQueue, &audioRxTaskMessage, 1) == pdPASS)
		{
			switch (audioRxTaskMessage.cmd)
			{
			case IS_PLAYING:
				audioTxTaskMessage.cmd = IS_PLAYING;
				audioTxTaskMessage.ret = audio.isRunning();
				xQueueSend(audioGetQueue, &audioTxTaskMessage, portMAX_DELAY);
				break;
			case SET_VOLUME:
				audioTxTaskMessage.cmd = SET_VOLUME;
				audio.setVolume(audioRxTaskMessage.value);
				audioTxTaskMessage.ret = 1;
				xQueueSend(audioGetQueue, &audioTxTaskMessage, portMAX_DELAY);
				break;
			case GET_VOLUME:
				uint16_t vol, steps;
				audioTxTaskMessage.cmd = GET_VOLUME;
				vol = audio.getVolume();
				steps = audio.maxVolume();
				audioTxTaskMessage.ret = ((uint32_t)vol << 16) | steps; // hi = vol setting, lo = max no of steps
				xQueueSend(audioGetQueue, &audioTxTaskMessage, portMAX_DELAY);
				break;
			case GET_RMS:
				audioTxTaskMessage.cmd = GET_RMS;
				// audioTxTaskMessage.ret = audio.getRMS();
				// xQueueSend(audioGetQueue, &audioTxTaskMessage, portMAX_DELAY);
				break;
			case CONNECTTOHOST:
				audioTxTaskMessage.cmd = CONNECTTOHOST;
				audioTxTaskMessage.ret = audio.connecttohost(audioRxTaskMessage.txt1);
				xQueueSend(audioGetQueue, &audioTxTaskMessage, portMAX_DELAY);
				break;
			case CONNECTTOSD:
				audioTxTaskMessage.cmd = CONNECTTOSD;
				log_i("msg: %s", audioRxTaskMessage.txt1);
				audioTxTaskMessage.ret = audio.connecttoFS(SPIFFS, audioRxTaskMessage.txt1);
				xQueueSend(audioGetQueue, &audioTxTaskMessage, portMAX_DELAY);
				break;
			case CONNECTTOSPEECH:
				// Serial.printf("msg: %s \n", audioRxTaskMessage.txt1);
				audioTxTaskMessage.cmd = CONNECTTOSPEECH;
				audioTxTaskMessage.ret = audio.connecttospeech(audioRxTaskMessage.txt1, audioRxTaskMessage.txt2);
				xQueueSend(audioGetQueue, &audioTxTaskMessage, portMAX_DELAY);
				// Serial.println(ESP.getFreeHeap());
				break;
			case AUDIO_STOP:
				audioTxTaskMessage.cmd = AUDIO_STOP;
				audio.stopSong();
				audioTxTaskMessage.ret = 1;
				xQueueSend(audioGetQueue, &audioTxTaskMessage, portMAX_DELAY);
				break;
			default:
				log_i("Audio task: error");
				break;
			}
		}
		audio.loop();

		if (!audio.isRunning())
		{
			sleep(1);
		}
		yield();
	}
	vTaskDelete(NULL);
}
// ---------------------------------------------------------------
audioMessage_t transmitReceive(audioMessage_t msg)
{
	xQueueSend(audioSetQueue, &msg, portMAX_DELAY);
	if (xQueueReceive(audioGetQueue, &audioRxMessage, portMAX_DELAY) == pdPASS)
	{
		if (msg.cmd != audioRxMessage.cmd)
		{
			log_e("wrong reply from message queue");
		}
		// log_i("transmitReceive successfully");
	}
	return audioRxMessage;
}
// ---------------------------------------------------------------
bool audioIsPlaying(void)
{
	audioTxMessage.cmd = IS_PLAYING;
	audioMessage_t RX = transmitReceive(audioTxMessage);
	return ((bool)RX.ret);
}
// ---------------------------------------------------------------
void audioStopSong()
{
	audioTxMessage.cmd = AUDIO_STOP;
	audioMessage_t RX = transmitReceive(audioTxMessage);
}
// ---------------------------------------------------------------
void audioSetVolume(uint8_t vol)
{
	log_i("audio start setvolume");
	audioTxMessage.cmd = SET_VOLUME;
	audioTxMessage.value = vol;
	audioMessage_t RX = transmitReceive(audioTxMessage);
}
// ---------------------------------------------------------------
// value scaled to 0-100% range
uint8_t audioGetVolumePerCent()
{
	audioTxMessage.cmd = GET_VOLUME;
	audioMessage_t RX = transmitReceive(audioTxMessage);
	uint16_t vol = (RX.ret >> 16) & 0xFF;
	uint16_t steps = RX.ret & 0xFF;
	return ((vol * 100) / steps);
}
// ---------------------------------------------------------------
uint32_t audioGetRMS()
{
	audioTxMessage.cmd = GET_RMS;
	audioMessage_t RX = transmitReceive(audioTxMessage);
	return RX.ret;
}
// ---------------------------------------------------------------
bool audioConnecttohost(const char *host)
{
	audioTxMessage.cmd = CONNECTTOHOST;
	audioTxMessage.txt1 = host;
	audioMessage_t RX = transmitReceive(audioTxMessage);
	return RX.ret;
}
// ---------------------------------------------------------------
bool audioConnecttoSD(const char *filename)
{
	log_i("Start connect to SD");
	audioTxMessage.cmd = CONNECTTOSD;
	audioTxMessage.txt1 = filename;
	audioMessage_t RX = transmitReceive(audioTxMessage);
	return RX.ret;
}
// ---------------------------------------------------------------
bool audioConnecttoSpeech(const char *host, const char *lang)
{
	// Serial.println("audioConnecttoSpeech 11");
	audioTxMessage.cmd = CONNECTTOSPEECH;
	audioTxMessage.txt1 = host;
	audioTxMessage.txt2 = lang;
	audioMessage_t RX = transmitReceive(audioTxMessage);
	return RX.ret;
}
// ---------------------------------------------------------------