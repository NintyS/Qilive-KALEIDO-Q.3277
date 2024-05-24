#include <libusb-1.0/libusb.h>
#include <stdio.h>

#include <iostream>

#define VENDOR_ID 0x04d9
#define PRODUCT_ID 0xa09f
#define INTERFACE 2

int set_color(libusb_device_handle *devh, libusb_context *ctx,
              unsigned char *data) {
  int transferred;
  int ret = libusb_control_transfer(
      devh, LIBUSB_REQUEST_TYPE_CLASS | LIBUSB_RECIPIENT_INTERFACE, 0x9, 0x300,
      INTERFACE, data, sizeof(data), 0);

  if (ret < 0) {
    fprintf(stderr, "Error while setting color\n");
    libusb_close(devh);
    libusb_exit(ctx);
    return 1;
  }

  return 0;
}

// Green Color 0 255 0
// unsigned char data[] = {0x27, 0x2B, 0x95, 0xFF, 0xE0, 0x45, 0x85, 0x6E};

// Red color 255 0 0
// unsigned char data[] = {0x27, 0x2B, 0x95, 0x04, 0xA8, 0x45, 0x7E, 0x76};

// Blue Color 0 0 255
// unsigned char data[] = {0x27, 0x2B, 0x95, 0xFF, 0xE0, 0x4A, 0x46, 0x76};

// Yellow Color 255 255 0
// unsigned char data[] = {0x27, 0x2B, 0x9D, 0x04, 0xA8, 0x45, 0x85, 0x6E};

// White Color 255 255 255
// unsigned char data[] = {0x27, 0x2b, 0x85, 0x04, 0xa8, 0x4a, 0x4d, 0x6e};

// Light Blue Color 0 255 255
// unsigned char data[] = {0x27, 0x2b, 0x9d, 0xff, 0xe0, 0x4a, 0x4d, 0x6e};

// Purple Color ( I don't remember the values XD )
// unsigned char data[] = {0x27, 0x26, 0x8d, 0x01, 0x88, 0x4a, 0x48, 0x86};

// Turned off ( Leds only )
// unsigned char data[] = {0x27, 0x2B, 0x55, 0xFF, 0xF0,0x4D, 0x7E, 0x76};

// Turn On leds
// unsigned char data[] = {0x27, 0x2b, 0x5d, 0xff, 0xf0, 0x4d, 0x85, 0x6e};

// Works but you can't return from this even after unplugging the device
// Red Breathing
// unsigned char data[] = {0x27, 0x2B, 0x45, 0xFF, 0xF8, 0x4D, 0x85, 0x6E};

// Neon mode
// unsigned char data[] = {0x27, 0x2b, 0x75, 0xff, 0xc8, 0x4d, 0x85, 0x6e};

// IDK line fast fadeing away?
// unsigned char data[] = {0x27, 0x2b, 0x4d, 0xff, 0x00, 0x4d, 0x85, 0x6e};

// Light on click
// unsigned char data[] = {0x27, 0x2b, 0x55, 0xff, 0xe8, 0x4d, 0x85, 0x6e};

// Green blinking with color switch
// unsigned char data[] = {0x27, 0x2B, 0x65, 0xFF, 0xD8, 0x4D, 0x85, 0x6E};

// Solid green / return to solid colors
// unsigned char data[] = {0x27, 0x2B, 0x5D, 0xFF, 0xF0, 0x4D, 0x85, 0x6E};

// Green breathing - we have probably two now beacuse red breathing changed color
// unsigned char data[] = {0x27, 0x2B, 0x45, 0xFF, 0xF8, 0x4D, 0x85, 0x6E};

// Wave mode?
// unsigned char data[] = {0x27, 0x2B, 0x7D, 0xFF, 0xD0, 0x4D, 0x85, 0x6E};

int main() {
  libusb_device_handle *devh;
  libusb_context *ctx = NULL;

  libusb_init(&ctx);
  devh = libusb_open_device_with_vid_pid(ctx, VENDOR_ID, PRODUCT_ID);
  if (!devh) {
    fprintf(stderr, "Can't open the device ( try with sudo )\n");
    return 1;
  }

  int input;

  for (;;) {
    std::cout << "=====================\n";
    std::cout << "1. Green Color\n";
    std::cout << "2. Red Color\n";
    std::cout << "3. Blue Color\n";
    std::cout << "4. Yellow Color\n";
    std::cout << "5. White Color\n";
    std::cout << "6. Light Blue Color\n";
    std::cout << "7. Purple Color\n";
    std::cout << "8. Neon mode\n";
    std::cout << "9. Color Stream Mode\n";
    std::cout << "10. On Click Wave\n";
    std::cout << "11. Blinking With Colors\n";
    std::cout << "12. Return To Solid Colors\n";
    std::cout << "13. Green Breathing\n";
    std::cout << "14. Wave\n";

    /////////////////////////////////////////////////////////

    std::cout << "15. Turn Off Leds\n";
    std::cout << "16. Turn On Leds\n";
    std::cout << "17. Red Breathing\n";
    std::cout << "18. Exit\n";
    std::cout << "=====================\n";

    std::cout << "Enter the color number: ";
    std::cin >> input;

    switch (input) {
    case 1: {
      unsigned char data1[] = {0x27, 0x2B, 0x95, 0xFF, 0xE0, 0x45, 0x85, 0x6E};
      set_color(devh, ctx, data1);
      break;
    }
    case 2: {
      unsigned char data2[] = {0x27, 0x2B, 0x95, 0x04, 0xA8, 0x45, 0x7E, 0x76};
      set_color(devh, ctx, data2);
      break;
    }
    case 3: {
      unsigned char data3[] = {0x27, 0x2B, 0x95, 0xFF, 0xE0, 0x4A, 0x46, 0x76};
      set_color(devh, ctx, data3);
      break;
    }
    case 4: {
      unsigned char data4[] = {0x27, 0x2B, 0x9D, 0x04, 0xA8, 0x45, 0x85, 0x6E};
      set_color(devh, ctx, data4);
      break;
    }
    case 5: {
      unsigned char data5[] = {0x27, 0x2b, 0x85, 0x04, 0xa8, 0x4a, 0x4d, 0x6e};
      set_color(devh, ctx, data5);
      break;
    }
    case 6: {
      unsigned char data6[] = {0x27, 0x2b, 0x9d, 0xff, 0xe0, 0x4a, 0x4d, 0x6e};
      set_color(devh, ctx, data6);
      break;
    }
    case 7: {
      unsigned char data7[] = {0x27, 0x26, 0x8d, 0x01, 0x88, 0x4a, 0x48, 0x86};
      set_color(devh, ctx, data7);
      break;
    }
    case 8: {
      unsigned char data8[] = {0x27, 0x2b, 0x75, 0xff, 0xc8, 0x4d, 0x85, 0x6e};
      set_color(devh, ctx, data8);
      break;
    }
    case 9: {
      unsigned char data8[] = {0x27, 0x2b, 0x4d, 0xff, 0x00, 0x4d, 0x85, 0x6e};
      set_color(devh, ctx, data8);
      break;
    }
    case 10: {
      unsigned char data8[] = {0x27, 0x2b, 0x55, 0xff, 0xe8, 0x4d, 0x85, 0x6e};
      set_color(devh, ctx, data8);
      break;
    }
    case 11: {
      unsigned char data8[] = {0x27, 0x2B, 0x65, 0xFF, 0xD8, 0x4D, 0x85, 0x6E};
      set_color(devh, ctx, data8);
      break;
    }
    case 12: {
      unsigned char data8[] = {0x27, 0x2B, 0x5D, 0xFF, 0xF0, 0x4D, 0x85, 0x6E};
      set_color(devh, ctx, data8);
      break;
    }
    case 13: {
      unsigned char data8[] = {0x27, 0x2B, 0x45, 0xFF, 0xF8, 0x4D, 0x85, 0x6E};
      set_color(devh, ctx, data8);
      break;
    }
    case 14: {
      unsigned char data8[] = {0x27, 0x2B, 0x7D, 0xFF, 0xD0, 0x4D, 0x85, 0x6E};
      set_color(devh, ctx, data8);
      break;
    }
    //////////
    case 15: {
      unsigned char data8[] = {0x27, 0x2B, 0x55, 0xFF, 0xF0, 0x4D, 0x7E, 0x76};
      set_color(devh, ctx, data8);
      break;
    }
    case 16: {
      unsigned char data8[] = {0x27, 0x2B, 0x5D, 0xFF, 0xF0, 0x4D, 0x85, 0x6E};
      set_color(devh, ctx, data8);
    }
    case 17: {
      unsigned char data9[] = {0x27, 0x2B, 0x45, 0xFF, 0xF8, 0x4D, 0x85, 0x6E};
      set_color(devh, ctx, data9);
      break;
    }
    case 18:
      goto exit_loop;
      break;

    default:
      std::cout << "Invalid input\n";
    }
    system("clear");
    input = 0;
  }

exit_loop:;

  // printf("Color set\n");

  libusb_close(devh);
  libusb_exit(ctx);
  return 0;
}
