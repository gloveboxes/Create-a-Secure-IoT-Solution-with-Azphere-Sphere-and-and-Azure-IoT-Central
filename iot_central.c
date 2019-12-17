//#include "iot_central.h"
//
//
///// <summary>
/////     Converts AZURE_SPHERE_PROV_RETURN_VALUE to a string.
///// </summary>
//static const char* getAzureSphereProvisioningResultString(
//	AZURE_SPHERE_PROV_RETURN_VALUE provisioningResult)
//{
//	switch (provisioningResult.result) {
//	case AZURE_SPHERE_PROV_RESULT_OK:
//		return "AZURE_SPHERE_PROV_RESULT_OK";
//	case AZURE_SPHERE_PROV_RESULT_INVALID_PARAM:
//		return "AZURE_SPHERE_PROV_RESULT_INVALID_PARAM";
//	case AZURE_SPHERE_PROV_RESULT_NETWORK_NOT_READY:
//		return "AZURE_SPHERE_PROV_RESULT_NETWORK_NOT_READY";
//	case AZURE_SPHERE_PROV_RESULT_DEVICEAUTH_NOT_READY:
//		return "AZURE_SPHERE_PROV_RESULT_DEVICEAUTH_NOT_READY";
//	case AZURE_SPHERE_PROV_RESULT_PROV_DEVICE_ERROR:
//		return "AZURE_SPHERE_PROV_RESULT_PROV_DEVICE_ERROR";
//	case AZURE_SPHERE_PROV_RESULT_GENERIC_ERROR:
//		return "AZURE_SPHERE_PROV_RESULT_GENERIC_ERROR";
//	default:
//		return "UNKNOWN_RETURN_VALUE";
//	}
//}
//
///// <summary>
/////     Converts the IoT Hub connection status reason to a string.
///// </summary>
//static const char* GetReasonString(IOTHUB_CLIENT_CONNECTION_STATUS_REASON reason)
//{
//	static char* reasonString = "unknown reason";
//	switch (reason) {
//	case IOTHUB_CLIENT_CONNECTION_EXPIRED_SAS_TOKEN:
//		reasonString = "IOTHUB_CLIENT_CONNECTION_EXPIRED_SAS_TOKEN";
//		break;
//	case IOTHUB_CLIENT_CONNECTION_DEVICE_DISABLED:
//		reasonString = "IOTHUB_CLIENT_CONNECTION_DEVICE_DISABLED";
//		break;
//	case IOTHUB_CLIENT_CONNECTION_BAD_CREDENTIAL:
//		reasonString = "IOTHUB_CLIENT_CONNECTION_BAD_CREDENTIAL";
//		break;
//	case IOTHUB_CLIENT_CONNECTION_RETRY_EXPIRED:
//		reasonString = "IOTHUB_CLIENT_CONNECTION_RETRY_EXPIRED";
//		break;
//	case IOTHUB_CLIENT_CONNECTION_NO_NETWORK:
//		reasonString = "IOTHUB_CLIENT_CONNECTION_NO_NETWORK";
//		break;
//	case IOTHUB_CLIENT_CONNECTION_COMMUNICATION_ERROR:
//		reasonString = "IOTHUB_CLIENT_CONNECTION_COMMUNICATION_ERROR";
//		break;
//	case IOTHUB_CLIENT_CONNECTION_OK:
//		reasonString = "IOTHUB_CLIENT_CONNECTION_OK";
//		break;
//	}
//	return reasonString;
//}