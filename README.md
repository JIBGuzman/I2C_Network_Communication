# I2C Communication Project

This project demonstrates the implementation of I2C communication using the TM4C123GH6PM microcontroller. The project includes functions for transmitting and receiving data over the I2C bus, as well as handling various I2C-related interrupts and errors.

## Project Structure

```
.vscode/
    c_cpp_properties.json
    launch.json
    settings.json
Project5P1/
    ButtonLED.c
    ButtonLED.h
    I2C.c
    I2C.h
    I2CMain.c
    I2CTestMain.c
    LCD.c
    LCD.h
    ModuleTest.c
    startup.s
    tm4c123gh6pm.h
Project5P2/
    build/
README.md
```

## Files and Directories

- **Project5P1/I2C.c**: Contains the implementation of I2C communication functions such as `I2C0_Receive` and `I2C0_Transmit`.
- **Project5P1/I2C.h**: Header file for I2C function declarations and macros.
- **Project5P1/I2CMain.c**: Main file demonstrating the use of I2C functions.
- **Project5P1/I2CTestMain.c**: Test file for I2C functions.
- **Project5P1/tm4c123gh6pm.h**: Register definitions for the TM4C123GH6PM microcontroller.
- **Project5P1/startup.s**: Startup assembly code for initializing the microcontroller and handling interrupts.
- **Project5P1/ButtonLED.c**: Example file for controlling LEDs with buttons.
- **Project5P1/LCD.c**: Example file for interfacing with an LCD.
- **Project5P1/ModuleTest.c**: Additional test file for various modules.

## I2C Functions

### I2C0_Receive

```c
uint8_t I2C0_Receive(uint8_t slave_addr, uint8_t slave_reg_addr);
```

This function receives data from a specified register of an I2C slave device.

- **Parameters**:
  - `slave_addr`: The address of the I2C slave device.
  - `slave_reg_addr`: The register address within the slave device to read from.
- **Returns**: The data read from the slave device or an error code if the operation fails.

### I2C0_Transmit

```c
uint8_t I2C0_Transmit(uint8_t slave_addr, uint8_t slave_reg_addr, uint8_t data);
```

This function transmits data to a specified register of an I2C slave device.

- **Parameters**:
  - `slave_addr`: The address of the I2C slave device.
  - `slave_reg_addr`: The register address within the slave device to write to.
  - 

data

: The data to be written to the slave device.
- **Returns**: An error code if the operation fails, otherwise 0.

## Register Definitions

### I2C_MCS Register

- **I2C_MCS_BUSY**: Indicates if the I2C bus is busy.

### I2C_MDR Register

- **I2C_MDR_DATA_M**: Mask for the data transferred.
- **I2C_MDR_DATA_S**: Shift for the data transferred.

### I2C_MTPR Register

- **I2C_MTPR_HS**: High-Speed Enable.
- **I2C_MTPR_TPR_M**: Timer Period mask.
- **I2C_MTPR_TPR_S**: Timer Period shift.

### I2C_MIMR Register

- **I2C_MIMR_CLKIM**: Clock Timeout Interrupt Mask.
- **I2C_MIMR_IM**: Master Interrupt Mask.

### I2C_MRIS Register

- **I2C_MRIS_CLKRIS**: Clock Timeout Raw Interrupt Status.

## Getting Started

1. **Clone the repository**:
   ```sh
   git clone <repository-url>
   ```

2. **Open the project in Visual Studio Code**:
   ```sh
   code .
   ```

3. **Build the project**:
   Use the build tasks defined in the 

.vscode

 directory to compile the project.

4. **Flash the microcontroller**:
   Use the appropriate tools to flash the compiled binary to the TM4C123GH6PM microcontroller.

5. **Run the project**:
   Connect the microcontroller to the I2C devices and run the project to see the I2C communication in action.

## License

This project is licensed under the terms of the Texas Instruments Software License Agreement. See the 

tm4c123gh6pm.h

 file for details.

## Acknowledgments

- This project is based on the TM4C123GH6PM microcontroller and uses code and examples provided by Texas Instruments.
- Special thanks to the contributors and maintainers of the project.

For more information, refer to the documentation and comments within the source code files.
