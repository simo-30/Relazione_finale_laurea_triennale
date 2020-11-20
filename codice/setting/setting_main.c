#include "setting.h"
#include <stdio.h>
#include <stdlib.h>
#pragma once

int main() {
	printf("Programma di prova per testare le funzioni della libreria 'setting.h'\n");
	SettingType* setting=read_setting("setting.txt");
	print_setting(setting);
	destroy_setting(setting);
	SettingType* set=new_settingType(4, 10, 10, 100);
	print_setting(set);
	return 0;
}
