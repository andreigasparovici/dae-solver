import pandas as pd
import matplotlib.pyplot as plt
import numpy as np


fig, ax = plt.subplots(1, 2, sharey=True)

fig.set_size_inches(22, 10)

for i in range(1, 6):
    df = pd.read_csv(f'solver-{i}.csv')

    rows, cols = df.shape

    t0, t = i, i+1
    step = .001

    X = np.linspace(t0, t, rows)

    for j, col in enumerate(df.columns):
        y = df[col].to_numpy()
        ax[j].plot(X, y, label=f'{col} {i}', marker='.')
        ax[j].set_xlabel('t')

for j in range(2):
    ax[j].legend()

plt.savefig('solver-out.png')

