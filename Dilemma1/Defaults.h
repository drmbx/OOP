<<<<<<< HEAD
#pragma once

#include "IStrategy.h"
#include "CompetitionEnum.h"

class Defaults {
public:
    static ReferenceTable GetDefaultPointsTable() {
        ReferenceTable scores;
        scores[C][C][C] = {7, 7, 7};
        scores[C][C][D] = {3, 3, 9};
        scores[C][D][C] = {3, 9, 3};
        scores[D][C][C] = {9, 3, 3};
        scores[C][D][D] = {0, 5, 5};
        scores[D][C][D] = {5, 0, 5};
        scores[D][D][C] = {5, 5, 0};
        scores[D][D][D] = {1, 1, 1};
        return scores;
    }

    static int GetDefaultSteps() {
        return 10;
    }

    static CompetitionEnum GetDefaultCompetition() {
        return Detailed;
    }
=======
#pragma once

#include "IStrategy.h"
#include "CompetitionEnum.h"

class Defaults {
public:
    static ReferenceTable GetDefaultPointsTable() {
        ReferenceTable scores;
        scores[C][C][C] = {7, 7, 7};
        scores[C][C][D] = {3, 3, 9};
        scores[C][D][C] = {3, 9, 3};
        scores[D][C][C] = {9, 3, 3};
        scores[C][D][D] = {0, 5, 5};
        scores[D][C][D] = {5, 0, 5};
        scores[D][D][C] = {5, 5, 0};
        scores[D][D][D] = {1, 1, 1};
        return scores;
    }

    static int GetDefaultSteps() {
        return 100;
    }

    static CompetitionEnum GetDefaultCompetition() {
        return Detailed;
    }
>>>>>>> d06e24c4321ce550dd3c016247dcbcd40e6427e5
};