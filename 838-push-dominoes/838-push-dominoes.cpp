class Solution {
public:
    string pushDominoes(string dominoes) {
        int r = 100001;
        for (int i = 0, end = dominoes.size(); i < end; ++i) {
            if (dominoes[i] == '.') {
                continue;
            }
            else if (dominoes[i] == 'R') {
                if (r >= 0) {
                    for (int j = r + 1; j < i; ++j) {
                        dominoes[j] = 'R';
                    }
                }
                r = i;
            }
            else {
                if (r == 100001) {
                    for (int j = 0; j < i; ++j) {
                        dominoes[j] = 'L';
                    }
                }
                else if (r < 0) {
                    for(int j = -r + 1; j < i; ++j) {
                        dominoes[j] = 'L';
                    }
                    r = -i;
                }
                else {
                    if (((r + i) & 1) == 0) {
                        for (int j = r + 1, e = (r + i) >> 1; j < e; ++j) {
                            dominoes[j] = 'R';
                        }
                        for (int j = ((r + i) >> 1) + 1; j < i; ++j) {
                            dominoes[j] = 'L';
                        }
                    }
                    else {
                        for (int j = r + 1, e = (r + i) >> 1; j <= e; ++j) {
                            dominoes[j] = 'R';
                        }
                        for (int j = ((r + i) >> 1) + 1; j < i; ++j) {
                            dominoes[j] = 'L';
                        }
                    }
                    r = -i;
                }
            }
        }
        if (r >= 0) {
            for (int i = r + 1, end = dominoes.size(); i < end; ++i) {
                dominoes[i] = 'R';
            }
        }
        return dominoes;
    }
};