import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

fig, ax = plt.subplots(1, 2)

fig.set_size_inches(22, 10)

iterations = 5

for i in range(1, iterations + 1):
    df = pd.read_csv(f'solver-{i}.csv')
    rows, cols = df.shape

    t0, t = i, i+1
    step = .001

    X = np.linspace(t0, t, rows)

    for j, col in enumerate(df.columns):
        y = df[col].to_numpy()
        ax[j].plot(X, y, label=str(i), marker='.')
        ax[j].set_xlabel('t')
        ax[j].set_ylabel(col)
        if j == 1:
            ax[j].set_yscale('log')

for j in range(2):
    ax[j].legend()

plt.savefig('solver.png')