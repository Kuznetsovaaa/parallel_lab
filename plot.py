import matplotlib.pyplot as plt

n = [200, 400, 800, 1000, 1200, 1600, 2000]
t = [0.027455, 0.269594, 2.45661, 7.80133, 9.723223, 45.6031, 88.6861]

plt.figure(figsize=(8, 5))
plt.plot(n, t, marker='o', color='navy')
plt.xlabel('Размер матрицы n')
plt.ylabel('Время, сек')
plt.title('Зависимость времени от размера матрицы')
plt.grid(True)
plt.savefig('graph.png', dpi=150)
print("Graph saved to graph.png")