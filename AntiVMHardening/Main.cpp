#include <iostream>
#include <Windows.h>

bool IsVMThroughDisplays()
{
	DISPLAY_DEVICE displayDevice;
	displayDevice.cb = sizeof(DISPLAY_DEVICE);
	DWORD deviceIndex = 0;

	while (EnumDisplayDevices(NULL, deviceIndex, &displayDevice, 0)) {

		std::wstring devicestring = displayDevice.DeviceString;
		if (devicestring.find(L"Microsoft Basic Display Adapter") != std::wstring::npos ||
			devicestring.find(L"Qemu") != std::wstring::npos ||
			devicestring.find(L"VMware SVGA") != std::wstring::npos ||
			devicestring.find(L"VirtualBox Graphics Adapter") != std::wstring::npos ||
			devicestring.find(L"Citrix Display Adapter") != std::wstring::npos ||
			devicestring.find(L"Parallels Display Adapter") != std::wstring::npos ||
			devicestring.find(L"Microsoft Remote Display Adapter") != std::wstring::npos)
		{

			printf("DeviceString: %ws\n", displayDevice.DeviceString);
			return true;
		}
		deviceIndex++;
	}
	return false;
}

void main()
{

	if (IsVMThroughDisplays())
	{
		std::cout << "VM Detected through Displays" << std::endl;
	}
	else
	{
		std::cout << "VM Not Detected through Displays" << std::endl;
	}
	system("pause");
}