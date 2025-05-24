import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# Load full cloud data (reshape assuming shape = 2000 x 50 x 3)
matrix_data = np.loadtxt("MatrixA.data")
cloud_data = matrix_data.reshape(2000, 50, 3)


iterations = [0, 666, 1333, 1999]

# Surface plot grid
X = np.linspace(-2, 2, 100)
Y = np.linspace(-1, 3, 100)
X, Y = np.meshgrid(X, Y)
Z = 100 * (Y - X**2)**2 + (6.4 * (Y - 0.5)**2 - X - 0.6)**2

# Start plotting
fig = plt.figure(figsize=(16, 12))
for idx, iter_num in enumerate(iterations, 1):
    cloud = cloud_data[iter_num]
    ax = fig.add_subplot(2, 2, idx, projection='3d')
    ax.plot_surface(X, Y, Z, cmap='jet', alpha=0.65, rstride=1, cstride=1, antialiased=True)
    ax.scatter(cloud[:, 0], cloud[:, 1], cloud[:, 2],
               c='black', s=35, edgecolors='white', linewidth=0.5, zorder=10)
    ax.set_title(f"CRS Cloud at Iteration {iter_num}")
    ax.set_xlabel("X")
    ax.set_ylabel("Y")
    ax.set_zlabel("f(x, y)")

plt.tight_layout()
plt.savefig("CRS_cloud_evolution.png", dpi=300)

