import math

slices = 256
result = []

for i in range(slices):
    # Calculate the phase angle for this slice (0 to 2π)
    theta = 2 * math.pi * i / slices
    # Sine value in range [-1, 1]
    s = math.sin(theta)
    # Map from [-1, 1] to [0, 255]
    mapped = int(round((s + 1) * 127.5))
    result.append(mapped)

# Print as a comma-separated list
print(', '.join(map(str, result)))