#include <libusb-1.0/libusb.h>
#include <stdio.h>

#define VENDOR_ID 0x04d9
#define PRODUCT_ID 0xa09f
#define INTERFACE 2

int main() {
  libusb_device_handle *devh;
  libusb_context *ctx = NULL;

  libusb_init(&ctx);
  devh = libusb_open_device_with_vid_pid(ctx, VENDOR_ID, PRODUCT_ID);
  if (!devh) {
    fprintf(stderr, "Nie można otworzyć urządzenia.\n");
    return 1;
  }

  // Ustaw kolor zielony
  unsigned char data[] = {0x27, 0x2B, 0x95, 0xFF, 0xE0, 0x45, 0x85, 0x6E};
  int transferred;
  int ret = libusb_control_transfer(
      devh, LIBUSB_REQUEST_TYPE_CLASS | LIBUSB_RECIPIENT_INTERFACE, 0x9, 0x300,
      INTERFACE, data, sizeof(data), 0);

  if (ret < 0) {
    fprintf(stderr, "Błąd podczas ustawiania koloru.\n");
    libusb_close(devh);
    libusb_exit(ctx);
    return 1;
  }

  printf("Kolor ustawiony na zielony.\n");

  libusb_close(devh);
  libusb_exit(ctx);
  return 0;
}
