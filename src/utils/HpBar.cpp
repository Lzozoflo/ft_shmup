//
// Created by tjooris on 11/30/25.
//

#include <ncurses.h>
#include <string>

void printHpBar(WINDOW *win, int y, int x, int hp, int maxHp, int width)
{
	if (width < 1) width = 1;

	if (hp < 0) hp = 0;
	if (hp > maxHp) hp = maxHp;

	int filled = (hp * width) / maxHp;
	int empty = width - filled;

	std::string bar = "|";
	bar += std::string(filled, '=');
	bar += std::string(empty, '-');
	bar += "|";

	mvwprintw(win, y, x, "HP : %s", bar.c_str());
}