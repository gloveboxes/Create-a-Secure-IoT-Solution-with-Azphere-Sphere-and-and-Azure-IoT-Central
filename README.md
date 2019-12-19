# Create a Secure IoT Solution with Azure Sphere and Azure IoT Central

![](resources/azure-sphere-iot-central-banner.png)

Follow me on Twitter [@dglover](https://twitter.com/dglover)

|Author|[Dave Glover](https://developer.microsoft.com/en-us/advocates/dave-glover?WT.mc_id=github-blog-dglover), Microsoft Cloud Developer Advocate |
|:----|:---|
|Target Platform | Seeed Studio Azure Sphere MT3620 |
|Developer Platform | Windows 10 or Ubuntu 18.04 |
|Azure SDK | Azure Sphere SDK 19.11 or better |
|Developer Tools| [Visual Studio (The free Community Edition or better)](https://visualstudio.microsoft.com/vs/?WT.mc_id=github-blog-dglover) or [Visual Studio Code (Free OSS)](https://code.visualstudio.com?WT.mc_id=github-blog-dglover)|
|Hardware | [Seeed Studio Grove Shield](https://www.seeedstudio.com/MT3620-Grove-Shield.html), and the [Grove Temperature and Humidity Sensor (SHT31)](https://www.seeedstudio.com/Grove-Temperature-Humidity-Sensor-SHT31.html) |
|Source Code | https://github.com/gloveboxes/Create-a-Secure-IoT-Solution-with-Azphere-Sphere-and-and-Azure-IoT-Central|
|Language| C|
|Date|As of December, 2019|

## What is Azure Sphere

Azure Sphere is a secured, high-level application platform with built-in communication and security features for internet-connected devices.

It comprises a secured, connected, crossover microcontroller unit (MCU), a custom high-level Linux-based operating system (OS), and a cloud-based security service that provides continuous, renewable security.

## Why Azure Sphere

As billions of new devices are connected, organisations need to secure them to help protect data, privacy, physical safety and infrastructure. Azure Sphere builds on decades of Microsoft experience in hardware, software and cloud to provide a turnkey solution for IoT devices. Get defence in depth to embrace IoT innovation with confidence.

## Tutorial Overview

1. Create an Azure IoT Central Application (Free trail)
2. Set up Azure IoT Central to work with Azure Sphere
3. Deploy an Azure IoT Central application to Azure Sphere

## Create an Azure IoT Central Application

### What is Azure IoT Central

Easily connect, monitor and manage your Internet of Things (IoT) assets at scale. [Azure IoT Central](https://azure.microsoft.com/en-in/services/iot-central/?WT.mc_id=pycon-blog-dglover) is a hosted, extensible software as a service (SaaS) platform that simplifies setup of your IoT solution and helps reduce the burden and costs of IoT management, operations and development. Provide customers superior products and service while expanding your business possibilities.

![Azure IoT Central](resources/azure-iot.png)

We are going to create an Azure IoT Central application, then a device, and finally a device **connection string** needed for the application that will run in the Docker container.

![](resources/azure_iot_central.png)

## Create a New IoT Central Application

1. Open the [Azure IoT Central](https://azure.microsoft.com/en-au/services/iot-central/?WT.mc_id=pycon-blog-dglover) in a new browser tab, then click **Getting started**.

2. Next, you will need to sign with your **Microsoft** Personal, or Work, or School account. If you do not have a Microsoft account, then you can create one for free using the **Create one!** link.

    ![iot central](resources/iot-central-login.png)

3. Create a new Azure IoT Central application, select **New Application**. This takes you to the **Create Application** page.

4. Select **Build as app**

    ![](resources/iot-central-build-first-app.png)

5. Select **Custom app**

    ![](resources/iot-central-custom-app.png)

### Create a **New application**

Specify **Application name**, **URL**, enable **7 day free trial**, and complete the registration form. Then click **Create**.

![](resources/iot-central-new-application.png)

1. Add new Device Template

    Click **Device templates**

    ![](resources/iot-central-device-template.png)

2. Select **IoT device** template type

    ![](resources/iot-central-new-iot-device-template.png)

3. Create an **IoT Device** Template

    1. Select **IoT device**,
    2. Click **Next:Customise**,
    3. Click **Next: Review**,
    4. Click **Create**.
    5. Name your template, and press **Enter**

#### Create a Capability Model

1. Add an Interface

    1. Click **Custom**,
	![](resources/iot-central-create-custom.png)
    2. Click the **+ Add interface** to add an **Interface**.
	![](resources/iot-central-add-interface.png)
    3. Choose **Custom** interface.
    ![](resources/iot-central-capability-model.png)

2. Add Capabilities

    ![](resources/iot-central-add-capability.png)

    Click **<** (Collapse) to create more working space.

3. Add **Humidity** Capability
    1. Click **+** to Add capability.
    1. Add **Humidity** Telemetry Capability
    2. Set the Unit to **%**

    ![](resources/iot-central-add-capability-humidity.png)

4. Add **Temperature** Capabilities

	* Display name: Temperature
	* Name: Temperature
	* Semantic type: Temperature
	* Units: C
	* Display Unit: C

4. Save the Capabilities

    Click **Save** to save the capabilities model.

	![](resources/iot-central-save-capabilities.png)

#### Create a Device Template View

1. Click **Views**
2. Click **Generate default views**
3. Click **Generate default dashboard view(s)**
4. You can customize the default view later.

    ![](resources/iot-central-create-view.png)

#### Publish the Template

Click **Publish** to activate the template, the click **Publish**.
![](resources/iot-central-publish-view.png)


## Set up Azure IoT Central to work with Azure Sphere

The Azure Sphere includes out of the box support for Azure IoT Hub and IoT Central.

For this tutorial we will be using the free trail on Azure IoT Central for its built in charting, analytics, device customization and the ability to "White Label" the solution.

### Step 1: Set up Azure IoT Central to work with your Azure Sphere tenant

Follow the [Set up Azure IoT Central to work with Azure Sphere](https://docs.microsoft.com/en-us/azure-sphere/app-development/setup-iot-central) guide.

In summary, you need to:

1. Open an Azure Sphere Developer Command Prompt
2. Authenticate ``` azsphere login ```
3. Download the Certificate Authority (CA) certificate for your Azure Sphere tenant ``` azsphere tenant download-CA-certificate --output CAcertificate.cer ```
4. Upload the tenant CA certificate to Azure IoT Central and generate a verification code
5. Verify the tenant CA certificate
6. Use the validation certificate to verify the tenant identity

### Step 2: Create an Azure Device in Azure IoT Central



From the Azure Sphere Developer Command Prompt, type the following command.

```bash
azsphere device show-attached
```

Note: The Create New Device dialog box in Azure IoT Central requires that the device ID be in lowercase characters. From the Azure Sphere Developer Command Prompt, enter the following command, which gets the ID of the attached device and converts it to lowercase:

```bash
powershell -Command ((azsphere device show-attached)[0] -split ': ')[1].ToLower()
```

#### Switch back to Azure IoT Central Web Portal

1. Select Devices from the side menu, then the Device Template previously created.
![](resources/iot-central-create-device.png)

2. Click **+ New** to add a new device
![](resources/iot-central-create-new-device.png)

3. Click **Create** to create the new device.



## Configure the Azure Sphere Application for Azure IoT Central

Review the [Azure IoT Central Sample ](https://github.com/Azure/azure-sphere-samples/blob/master/Samples/AzureIoT/IoTCentral.md) guide.

### Step 1: Clone the Azure Sphere Samples

```bash
git clone https://github.com/Azure/azure-sphere-samples.git
```

### Step 2: Config the Azure Sphere Application

Clone the tutorial sample.

1. Clone this tutorial sample application.
	```bash
	git clone https://github.com/gloveboxes/Create-a-Secure-IoT-Solution-with-Azphere-Sphere-and-and-Azure-IoT-Central.git
	```
2. Open the cloned solution with Visual Studio
3. Open the app_manifest.json file
4. Set the default Azure Sphere Tenant
	You may need to select the default Azure Sphere Tenant. Use the ```azsphere tenant list``` command to list available tenants, use the ```azsphere tenant select -i <guid>``` to select the default tenant.
5. From the Azure Sphere Developer Command Prompt, issue the following command to get the tenant ID. Copy the returned value and paste it into the DeviceAuthentication field of the app_manifest.json file:

	```bash
	azsphere tenant show-selected
	```

6. From the Azure Sphere Developer Command Prompt, run the ShowIoTCentralConfig.exe program from the sample repository (the ShowIoTCentralConfig program is located in the *azure-sphere-samples\Samples\AzureIoT\Tools* folder).

	```bash
	ShowIoTCentralConfig
	```

	When prompted, log in with the credentials you use for Azure IoT Central.

	The output of this command will be similar as follows:

	```
	Are you using a Work/School account to sign into your IoT Central Application (Y/N) ?

	Getting your IoT Central applications
	You have one IoT Central application 'yourappname-iot-central'.
	Getting the Device Provisioning Service (DPS) information.
	Getting a list of IoT Central devices.

	Find and modify the following lines in your app_manifest.json:
	"CmdArgs": [ "0ne9992KK6D" ],
	"AllowedConnections": [ "global.azure-devices-provisioning.net", "saas-iothub-9999999-f33a-4002-4444-7ca8989898989.azure-devices.net" ],
	"DeviceAuthentication": "--- YOUR AZURE SPHERE TENANT ID--- ",
	```
7. 	Copy the information from the output into the app_manifest.json file in Visual Studio. You *app_manifest.json* file will look similar to the follow:

	```json
	{
	"SchemaVersion": 1,
	"Name": "AzureSphereBlink1",
	"ComponentId": "a3ca0929-5f46-42b0-91ba-d5de1222da86",
	"EntryPoint": "/bin/app",
	"CmdArgs": [ "0ne9992KK6D" ],
	"Capabilities": {
		"Gpio": [ 9 ],
		"Uart": [ "ISU0" ],
		"AllowedConnections": [ "global.azure-devices-provisioning.net", "saas-iothub-9999999-f33a-4002-4444-7ca8989898989.azure-devices.net" ],
		"DeviceAuthentication": "999x999xeb-e021-43ce-8gh8-8k9lp888494"
	},
	"ApplicationType": "Default"
	}
	```

## Understanding the main.c Code

From Visual Studio, open the main.c file.

Review the following functions.

### InitPeripheralsAndHandlers

Sets up SIGTERM termination handler, initialize peripherals, and set up event handlers.

```c
static int InitPeripheralsAndHandlers(void)
{
	struct sigaction action;
	memset(&action, 0, sizeof(struct sigaction));
	action.sa_handler = TerminationHandler;
	sigaction(SIGTERM, &action, NULL);

	epollFd = CreateEpollFd();
	if (epollFd < 0) {
		return -1;
	}

	// Change this GPIO number and the number in app_manifest.json if required by your hardware.
	blinkOnSendGpioFd = GPIO_OpenAsOutput(9, GPIO_OutputMode_PushPull, GPIO_Value_High);
	if (blinkOnSendGpioFd < 0) {
		Log_Debug(
			"Error opening GPIO: %s (%d). Check that app_manifest.json includes the GPIO used.\n",
			strerror(errno), errno);
		return -1;
	}

	// Initialize Grove Shield and Grove Temperature and Humidity Sensor
	GroveShield_Initialize(&i2cFd, 115200);
	sht31 = GroveTempHumiSHT31_Open(i2cFd);

	// timer event for sending telemetry to Azure IoT Central
	azureIoTPollPeriodSeconds = AzureIoTDefaultPollPeriodSeconds;
	struct timespec azureTelemetryPeriod = { azureIoTPollPeriodSeconds, 0 };

	azureTimerFd = CreateTimerFdAndAddToEpoll(epollFd, &azureTelemetryPeriod, &azureEventData, EPOLLIN);
	if (azureTimerFd < 0) {
		return -1;
	}

	return 0;
}
```

### ClosePeripheralsAndHandlers

Closes peripherals and handlers.

```c
static void ClosePeripheralsAndHandlers(void)
{
	Log_Debug("Closing file descriptors\n");
	CloseFdAndPrintError(blinkOnSendGpioFd, "SendBlinker");
	CloseFdAndPrintError(azureTimerFd, "AzureTimer");
	CloseFdAndPrintError(epollFd, "Epoll");
}
```

### GetTelemetry

Reads sensor telemetry and returns the data as a JSON object.

```c
static int ReadTelemetry(char eventBuffer[], size_t len) {
	GroveTempHumiSHT31_Read(sht31);
	float temperature = GroveTempHumiSHT31_GetTemperature(sht31);
	float humidity = GroveTempHumiSHT31_GetHumidity(sht31);

	static const char* EventMsgTemplate = "{ \"Temperature\": \"%3.2f\", \"Humidity\": \"%3.1f\" }";
	return snprintf(eventBuffer, len, EventMsgTemplate, temperature, humidity);
}
```
