import matplotlib.pyplot as plt
import pandas as pd

files = [
    "elast-la.csv",
    "elast-lv.csv",
    "elast-ra.csv",
    "elast-rv.csv"
]


fig, ax = plt.subplots(2, 2)

fig.set_size_inches(20, 10)

for i, f in enumerate(files):
    df = pd.read_csv(f)
    x = df['DenormTime'].to_numpy()
    y = df['DenormValue'].to_numpy()

    name = f.split('.')[0].split('-')[1].upper()

    ax[i//2, i % 2].plot(x, y, marker='.', label=f'Elastance {name}')
    ax[i//2, i % 2].set_xlabel('t')
    ax[i//2, i % 2].legend()

plt.savefig('elastance.png')
