import sys
from fractions import Fraction

def main():
    # Fast input
    input = sys.stdin.readline

    n = int(input())
    seen = 0
    distinct_count = 0

    # Process input and count distinct numbers
    for num in map(int, input().split()):
        if not (seen & (1 << (num - 1))):
            seen |= (1 << (num - 1))
            distinct_count += 1

    # Calculate probability as a fraction
    numerator = 1 << distinct_count  # This is 2^distinct_count
    denominator = 1 << n  # This is 2^n
    
    result = Fraction(numerator, denominator)

    # Convert to float and print with high precision
    print(f"{float(result):.15f}")

if __name__ == "__main__":
    main()