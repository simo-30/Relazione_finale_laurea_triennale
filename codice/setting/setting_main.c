#include "setting.h"
#include <stdio.h>
#include <stdlib.h>
#pragma once

int main() {
	printf("Programma di prova per testare le funzioni della libreria 'setting.h'\n");
	SettingType* setting=read_setting("setting.txt");
	print_setting(setting);
	destroy_setting(setting);
	return 0;
}
