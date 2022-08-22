# Key 
- `x` represents any integer variable

# Getting Bits
| Get | Code |
| --- | ---- |
| Right-most bit | `x & -x` |

# Setting Bits
| Set | Code |
| --- | ---- |
| Last bit to 0 | `x & (x-1)` |

# Check Bits
| Check if | Code |
| --- | ---- |
| Last bit is set | `x & 1` | 

# Common Math
| Math | Code | 
| ---- | ---- | 
| Power of Two | `x & (-x) == x` |

# Axioms
- A power of two contains just one 1-bit
