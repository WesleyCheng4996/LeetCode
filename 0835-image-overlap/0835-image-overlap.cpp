class Solution {
public:
    int isEqual(vector<vector<int>>& img1, vector<vector<int>>& img2, int offset_i, int offset_j) {
        int ret = 0;
        if (offset_i < 0) {
            if (offset_j < 0) {

                for (int i = 0; i < img1.size() + offset_i; ++i) {
                    for (int j = 0; j < img1[0].size() + offset_j; ++j) {
                        if (img1[i - offset_i][j - offset_j] == img2[i][j] && img1[i - offset_i][j - offset_j] == 1) {
                            ++ret;
                        }
                    }
                }

            }
            else {

                for (int i = 0; i < img1.size() + offset_i; ++i) {
                    for (int j = 0; j < img1[0].size() - offset_j; ++j) {
                        if (img1[i - offset_i][j] == img2[i][j + offset_j] && img1[i - offset_i][j] == 1) {
                            ++ret;
                        }
                    }
                }

            }
        }
        else {
            if (offset_j < 0) {

                for (int i = 0; i < img1.size() - offset_i; ++i) {
                    for (int j = 0; j < img1[0].size() + offset_j; ++j) {
                        if (img1[i][j - offset_j] == img2[i + offset_i][j] && img1[i][j - offset_j] == 1) {
                            ++ret;
                        }
                    }
                }

            }
            else {

                for (int i = 0; i < img1.size() - offset_i; ++i) {
                    for (int j = 0; j < img1[0].size() - offset_j; ++j) {
                        if(img1[i][j] == img2[i + offset_i][j + offset_j] && img1[i][j] == 1) {
                            ++ret;
                        }
                    }
                }

            }

        }
        return ret;
    }


    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int ret = 0;
        int sz1 = img1.size(), sz2 = img1[0].size();
        for (int i = -sz1 + 1; i < sz1; ++i) {
            for (int j = -sz2 + 1; j < sz2; ++j) {
                ret = max(ret, isEqual(img1, img2, i, j));
            }
        }
        return ret;
    }
};