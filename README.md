## Integrating with Azure IoT Central

The Azure Sphere includes out of the box support for Azure IoT Hub and IoT Central. For this tutorial
I'm using Azure IoT Central for built in charting, analytics, device customization and the ability to "White Label" with my own branding.

Review [Set up Azure IoT Central to work with Azure Sphere](https://docs.microsoft.com/en-us/azure-sphere/app-development/setup-iot-central)

In summary:

1. Open an Azure Sphere Developer Command Prompt
2. Authenticate ``` azsphere login ```
3. Download the Certificate Authority (CA) certificate for your Azure Sphere tenant ``` azsphere tenant download-CA-certificate --output CAcertificate.cer ```
4. Upload the tenant CA certificate to Azure IoT Central and generate a verification code
5. Verify the tenant CA certificate
6. Use the validation certificate to verify the tenant identity