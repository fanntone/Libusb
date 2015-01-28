/*
 * libusb example program to list devices on the bus
 * Copyright (C) 2007 Daniel Drake <dsd@gentoo.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include <stdio.h>
#include <sys/types.h>
#include <time.h>
#include <libusb.h>

static void print_devs(libusb_device **devs)
{
	libusb_device *dev;
	int i = 0;

	while ((dev = devs[i++]) != NULL) {
		struct libusb_device_descriptor desc;
		int r = libusb_get_device_descriptor(dev, &desc);
		if (r < 0) {
			fprintf(stderr, "failed to get device descriptor");
			return;
		}

		printf("%04x:%04x (bus %d, device %d)\n",
			desc.idVendor, desc.idProduct,
			libusb_get_bus_number(dev), libusb_get_device_address(dev));
	}
}

int main(void)
{
	libusb_device **devs;
	int r;
	ssize_t cnt;
	int countdev = 0;
	for (int i = 0; i < 100; i++)
	{
		r = libusb_init(NULL);
		if (r < 0)
			return r;

		cnt = libusb_get_device_list(NULL, &devs);
		if (cnt < 0)
			return (int) cnt;
		if (countdev == 0 )
		{
			countdev = cnt;
		}
		else if (cnt > countdev)
		{
			countdev = cnt;
			system("D:\\JUCEtest.exe");
		}
		else if ( cnt <= countdev)
		{
			countdev = cnt;
		}
		printf("\n=======%d=========",i);
		print_devs(devs);
		libusb_free_device_list(devs, 1);
		printf("===================\n");
		Sleep(2000);
	}
	
	libusb_free_device_list(devs, 1);

	libusb_exit(NULL);
	return 0;
}

