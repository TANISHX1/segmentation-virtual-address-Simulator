# segmentation-virtual-address-Simulator
This C program simulates segmentation-based virtual memory translation in an operating system. It models how a 16-bit virtual address is divided into a segment number and an offset, and how this is used to compute a corresponding physical address using a simple segment table.

It generates a random virtual address, decodes it into segment and offset parts, and checks which of the four predefined segments (CODE, DATA, HEAP, STACK) it belongs to. Each segment is assigned a fixed size (16 KB) and is stored contiguously in physical memory. The program then calculates the physical address using the segment's base and offset, simulating how memory translation works in real systems using segmentation.

# Assumptions
  --segment has fixed size (16KB)
  --Segments are stored contiguously in physical memory.
  --Every process have 4 segments(CODE ,DATA , HEAP ,STACK)

# Work Flow
1. Generate a random 16-bit virtual address using random_number() and binaryconv().

2. Validate the random generated address:
    -If it's > 65536, address is valid. 
    -else print error and exit.

3. Initialize 4 segments: CODE, DATA, HEAP, STACK.

4. Assign segment number & name using binary().
5. Extract offset bits from virtual address using copy().
6. Set base and bound:
    -First segment base = 0
    -Others: base = previous base + 16384

7. Search for matching segment based on segment number & Check Offset fault .
8. If match found, print the matched segment info and compute:
    - Offset (in decimal)
    - Physical address = base + offset.
