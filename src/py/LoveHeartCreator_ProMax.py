import numpy as np
import matplotlib.pyplot as plt

def f(x, y):
    return ((x**2 + y**2 - 9)** 3 - 5.201314 * x**2 * y**3)

# 生成网格点
x = np.linspace(-4, 4, 2000)
y = np.linspace(-5, 5, 2000)
X, Y = np.meshgrid(x, y)

# 计算函数值
Z = f(X, Y)

# 创建图形
plt.figure(figsize=(8, 8))

# 绘制实心区域
plt.contourf(
    X, Y, Z,
    levels=[-np.inf, 0],
    colors='red',
    alpha=1
)

# 设置标题
plt.title("I LOVE YOU", fontsize=12)  # 标题字体大小可调整

# 隐藏坐标轴
plt.axis('off')
plt.axis('equal')
plt.tight_layout(pad=0)
plt.show()
