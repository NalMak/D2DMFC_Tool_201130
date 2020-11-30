#pragma once
#include "Singleton.h"

class DeviceManager : public Singleton<DeviceManager>
{
public:
	explicit DeviceManager() = default;
	~DeviceManager();
public:
	HRESULT Initialize();

private:
	void Check_SDKVersion();
	void CheckMultiSample();
	void CreateSwapChain(D3DPRESENT_PARAMETERS* _desc);
	void CreateDevice(D3DPRESENT_PARAMETERS* _desc);
	void Release();
public:	
	void Begin();
	void End();
public:
	PDIRECT3DDEVICE9 GetDevice() { assert("Can't find device" && m_device); return m_device; }
private:
	PDIRECT3D9 m_SDK = nullptr;
	PDIRECT3DDEVICE9 m_device = nullptr;
	DWORD m_msQualityLev;
	DWORD m_behaviourFlag;
	bool m_displayMode;
};

