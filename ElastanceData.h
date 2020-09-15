//
// Created by andrei on 14.09.2020.
//

#ifndef DAE_SOLVER_ELASTANCEDATA_H
#define DAE_SOLVER_ELASTANCEDATA_H


const int ELASTANCE_SIZE = 151;

const double elastanceTime[ELASTANCE_SIZE] = {
        0, 0.02, 0.04, 0.06, 0.08, 0.1, 0.12, 0.14, 0.16, 0.18, 0.2, 0.22, 0.24, 0.26, 0.28, 0.3, 0.32, 0.34, 0.36,
        0.38, 0.4, 0.42, 0.44, 0.46, 0.48, 0.5, 0.52, 0.54, 0.56, 0.58, 0.6, 0.62, 0.64, 0.66, 0.68, 0.7, 0.72, 0.74,
        0.76, 0.78, 0.8, 0.82, 0.84, 0.86, 0.88, 0.9, 0.92, 0.94, 0.96, 0.98, 1, 1.02, 1.04, 1.06, 1.08, 1.1, 1.12,
        1.14, 1.16, 1.18, 1.2, 1.22, 1.24, 1.26, 1.28, 1.3, 1.32, 1.34, 1.36, 1.38, 1.4, 1.42, 1.44, 1.46, 1.48, 1.5,
        1.52, 1.54, 1.56, 1.58, 1.6, 1.62, 1.64, 1.66, 1.68, 1.7, 1.72, 1.74, 1.76, 1.78, 1.8, 1.82, 1.84, 1.86, 1.88,
        1.9, 1.92, 1.94, 1.96, 1.98, 2, 2.02, 2.04, 2.06, 2.08, 2.1, 2.12, 2.14, 2.16, 2.18, 2.2, 2.22, 2.24, 2.26,
        2.28, 2.3, 2.32, 2.34, 2.36, 2.38, 2.4, 2.42, 2.44, 2.46, 2.48, 2.5, 2.52, 2.54, 2.56, 2.58, 2.6, 2.62, 2.64,
        2.66, 2.68, 2.7, 2.72, 2.74, 2.76, 2.78, 2.8, 2.82, 2.84, 2.86, 2.88, 2.9, 2.92, 2.94, 2.96, 2.98, 3
};

const double elastanceValue[ELASTANCE_SIZE] = {
        0.0592, 0.08271290323, 0.1060587097, 0.1292374194, 0.1522490323, 0.1750935484, 0.1977709677, 0.2202812903,
        0.2426245161, 0.2648006452, 0.2868096774, 0.3086516129, 0.3303264516, 0.3518341935, 0.3731748387, 0.3943483871,
        0.4153548387, 0.4361941935, 0.4568664516, 0.4773716129, 0.4977096774, 0.5178806452, 0.5378845161, 0.5577212903,
        0.5773909677, 0.5968935484, 0.6162290323, 0.6353974194, 0.6543987097, 0.6732329032, 0.6919, 0.7104, 0.7288,
        0.7471, 0.7652, 0.7832, 0.8011, 0.8188, 0.8364, 0.8538, 0.871, 0.888, 0.9045, 0.9199, 0.9356, 0.9509, 0.964,
        0.977, 0.9875, 0.9932, 0.9941, 0.9902, 0.9805, 0.9643, 0.9417, 0.9129, 0.877, 0.834, 0.7851, 0.7314, 0.6753,
        0.6167, 0.5577, 0.5019, 0.4513, 0.4055, 0.35154, 0.29758, 0.24362, 0.18966, 0.14, 0.105, 0.0875, 0.07, 0.06,
        0.055, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.0495, 0.0491,
        0.049002602, 0.048984055, 0.049002473, 0.049022772, 0.049110322, 0.049345686, 0.049809014, 0.050481407,
        0.051116675, 0.051454237, 0.051498604, 0.051461049, 0.051556786, 0.051895414, 0.05241459, 0.053036173,
        0.053682022, 0.054273996, 0.054733968, 0.055010994, 0.055137289, 0.055160923, 0.055129963, 0.055092331,
        0.055079104, 0.055089089, 0.055117443, 0.055159327, 0.055209901, 0.055264324, 0.055317804, 0.055368377,
        0.055418379, 0.05547051, 0.055527466, 0.055591947, 0.055666651, 0.055754105, 0.055854266, 0.055965112,
        0.056084572, 0.056210574, 0.056341046, 0.056474018, 0.056609357, 0.056748524, 0.056893028, 0.057044383,
        0.057204098, 0.057373687, 0.057554643, 0.057747032, 0.057948469, 0.058156328, 0.058367982, 0.058580803,
        0.058792164, 0.058999439, 0.0592
};

#endif //DAE_SOLVER_ELASTANCEDATA_H