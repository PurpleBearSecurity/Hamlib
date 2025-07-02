# Yaesu FTX-1 Support for Hamlib

## Overview

This implementation adds support for the Yaesu FTX-1 radio to the Hamlib library. The FTX-1 is a transceiver that connects via USB (as a serial port) and uses the Yaesu CAT protocol.

## Implementation Details

### Files Created/Modified

1. **`rigs/yaesu/ftx1.h`** - Header file defining FTX-1 specific constants and structures
2. **`rigs/yaesu/ftx1.c`** - Main implementation file for FTX-1 support
3. **`include/hamlib/riglist.h`** - Added `RIG_MODEL_FTX1` definition
4. **`rigs/yaesu/yaesu.h`** - Added extern declaration for `ftx1_caps`
5. **`rigs/yaesu/yaesu.c`** - Added registration of FTX-1 rig
6. **`rigs/yaesu/Makefile.am`** - Added FTX-1 files to build system

### Key Features

- **Serial Connection**: The FTX-1 connects via USB, which appears as a serial port (just like the FT991)
- **Frequency Ranges**: 
  - HF: 1.8-54 MHz
  - VHF: 144-148 MHz  
  - UHF: 430-450 MHz
- **Modes**: SSB, CW, FM, AM, RTTY, DATA, C4FM
- **Power**: Up to 100W on HF/6m, 50W on VHF/UHF
- **Memory**: 117 memory channels
- **CAT Protocol**: Uses Yaesu's new CAT protocol (similar to Kenwood)

### Implementation Approach

The implementation is based on the FT991 code since the FTX-1 has similar capabilities and also uses a serial port (via USB). Key differences:

1. **Port Type**: Uses `RIG_PORT_SERIAL` (same as FT991)
2. **Status**: Set to `RIG_STATUS_ALPHA` for initial implementation
3. **Version**: Set to `NEWCAT_VER ".1"` for first version

### Testing

A simple test program (`test_ftx1.c`) is included to verify the implementation can be loaded and initialized correctly.

## Usage

To use the FTX-1 with Hamlib applications:

```c
RIG *rig = rig_init(RIG_MODEL_FTX1);
// Configure serial port settings (the radio appears as a serial port over USB)
// Use standard Hamlib API calls
```

## Status

- **Status**: Alpha - Initial implementation
- **Connection**: Serial (via USB, not a distinct port type)
- **Protocol**: Yaesu CAT (new style, Kenwood-like commands)

## Future Work

1. Test with actual FTX-1 hardware
2. Verify serial port connection parameters
3. Test all CAT commands
4. Update status to STABLE once tested
5. Add any FTX-1 specific features not present in FT991

## Author

Jeremy Miller KO4SSD (ko4ssd at ko4ssd.com) - 2025

Based on FT991 implementation by Nate Bargmann (n0nb at arrl.net) and others. 