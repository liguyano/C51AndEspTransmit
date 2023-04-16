cmake_minimum_required(VERSION 3.25)
project(car_driver)

set(CMAKE_C_STANDARD 17)
INCLUDE_DIRECTORIES(E:\\Keil_v5\\C51\\INC\\Atmel E:\\Keil_v5\\C51\\INC\\STC E:\\Keil_v5\\C51\\INC 
        )
add_executable(car_driver main.c Transport.c Transport.h)
