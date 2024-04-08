#pragma once

namespace vars {
	bool debug = false;
	bool tab = 0;
	bool EnableNoRecoil = false;
	bool EnableInfiniteAmmo = false;
	bool isSetTargetRecoilHooked = false;
	bool isInfiniteAmmoHooked = false;
	float recoilValue = 0.0f;

	namespace offsets {
		uintptr_t GameAssembly = (uintptr_t)GetModuleHandle("GameAssembly.dll");

		uintptr_t setTargetRecoilRVA = 0;// 0x46D22B0;
		uintptr_t set_ChargedAmmoLeftRVA = 0;// 0x10F8A20;
	}

}
