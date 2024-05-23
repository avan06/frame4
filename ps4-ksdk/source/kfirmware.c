#include "kfirmware.h"

unsigned short cachedFirmware;

int streq(const char *s1, const char *s2) {
	while (*s1 == *s2 && *s1) {
		s1++;
		s2++;
	}

	return *s1 == *s2;
}

unsigned short kget_firmware_from_base(uint64_t kernbase) {
	if (cachedFirmware) {
		return cachedFirmware;
	}

    char *firmwareString = "firmware";
    
    char *fw0505 = (char *)(kernbase + 0x7C7350);
	char *fw0672 = (char *)(kernbase + 0x827FB9);
    char *fw0702 = (char *)(kernbase + 0x827145);
    char *fw0900 = (char *)(kernbase + 0x7E1127);
	char *fw1100 = (char *)(kernbase + 0x8011AE);

    if (streq(fw0505, firmwareString)) {
        cachedFirmware = 505;
        return 505;
    }

	if (streq(fw0672, firmwareString)) {
        cachedFirmware = 672;
        return 672;
    }

    if (streq(fw0702, firmwareString)) {
        cachedFirmware = 702;
        return 702;
    }

    if (streq(fw0900, firmwareString)) {
        cachedFirmware = 900;
        return 900;
    }

	if (streq(fw1100, firmwareString)) {
        cachedFirmware = 1100;
        return 1100;
    }

    return 0;
}
