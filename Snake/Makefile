#Path to arduino sources
ARDUINO_DIR = /usr/share/arduino

#Path to arduino device
ARDUINO_PORT = /dev/ttyUSB0

#Arduinno Model
BOARD_TAG = uno

USER_LIB_PATH = $(realpath .)/lib
ARDUINO_LIBS += matrix_driver
ARDUINO_SKETCH_BOOK = ${USER_LIB_PATH}

#Includes Arduino make file for building and flashing the scketch
include ${ARDUINO_DIR}/Arduino.mk

