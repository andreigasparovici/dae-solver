import pandas as pd
import matplotlib.pyplot as plt
import numpy as np


fig, ax = plt.subplots(1, 2, sharey=True)

fig.set_size_inches(40, 20)

for i in range(1, 6):
    df = pd.read_csv(f'solver-{i}.csv')

    rows, cols = df.shape

    t0, t = i, i+1
    step = .001

    X = np.linspace(t0, t, rows)

    for j, col in enumerate(df.columns):
        y = df[col].to_numpy()
        ax[j].plot(X, y, label=f'{col} {i}')
        ax[j].set_xlabel('t')
        # if j == 1:
        #     ax[j].set_yscale('log')

for j in range(2):
    ax[j].legend()

plt.savefig('solver-out.png')
