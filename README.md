# Developer's Hint to the reviewer - Week2:

The extensions are added in concersion.c and conversion.h files.

##Conversion logic:

Step 1 : Calculate Maximum Raw value of the converter e.g. (2^12 - 2)== for 12 bit converter

Step 2 : Calculate Resolution for Internal to Physical conversion

Step 3 : Caluclate Offset using Minimum Physical Value

Step 4 : Execute the Conversion  (Input raw value * Resolution + Offset)

Step 5 : Calculate the Roundoff value

Step 6 : Calculate Bbsoulte value

Step 7 : Call Legacy code(last week assignment) to calculate the Continous Range where the Input is the Converted Absolute Value from Step6.

# Developer's Hint to the reviewer - Week1:
The code gets the input and validates the array.
**Validation condition:** : Input array should be an integer value between  0 and 65535

If the validation is TRUE then sort the given input , calculates the continuous ranges and readings , store it in a structure and print the output.

If the validation is FALSE then exit the code after printing "Input is Invalid"

For the test purpose, the PrintingErrorMessage function is stubbed with another function where exiting the program is not used.



# Test Driven Ranges

The charging current varies during the process of charging.
We need to capture the range of current measurements -
what range of currents are most often encountered while charging.

> **DO NOT** jump into implementation! Read the example and the starting task below.

## Example

### Input

Consider a set of periodic current samples from a charging session to be:
`3, 3, 5, 4, 10, 11, 12`

### Functionality

The continuous ranges in there are: `3,4,5` and `10,11,12`.

The task is to detect the ranges and
output the number of readings in each range.

In this example,

- the `3-5` range has `4` readings
- the `10-12` range has `3` readings.

### Output

The expected output would be in comma-separated (csv format):

```
Range, Readings
3-5, 4
10-12, 3
```

## Tasks

Establish quality parameters: 

- What is the maximum complexity (CCN) per function? 4 CCN and create corresponding yml in the `.github/workflows` folder
- How many lines of duplicate code will you tolerate? 3 the number of lines and create corresponding yml in the `.github/workflows` folder
- Ensure 100% line and branch coverage at every step. Include the coverage yml in the workflows.

Adapt/adopt/extend the `yml` files from one of your previous workflow folders.

Start Test-driven approach

1. Write the smallest possible failing test: give input `4,5`. assert output to be `4-5, 2`.
1. Write the minimum amount of code that'll make it pass.
1. Refactor any assumptions, continue to pass this test. Do not add any code without a corresponding test.




