/*
 * DIP plugin for Custom IOS.
 *
 * Copyright (C) 2008-2010 Waninkoko, WiiGator.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "syscalls.h"

/* Variables */
static s32 fd = -1;


s32 File_Open(const char *path)
{
	/* Open file */
	fd = os_open(path, 0);
	if (fd < 0)
		return fd;

	return 0;
}

void File_Close(void)
{
	/* Close file */
	if (fd >= 0)
		os_close(fd);

	/* Reset descriptor */
	fd = -1;
}

s32 File_Read(void *buffer, u32 len, u32 offset)
{
	s32 ret;

	/* Seek file */
	ret = os_seek(fd, offset << 2, 0);
	if (ret < 0)
		return ret;

	/* Read file */
	ret = os_read(fd, buffer, len);
	if (ret < 0)
		return ret;

	return 0;
}
