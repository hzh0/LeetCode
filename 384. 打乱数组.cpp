class Solution {
public:
	Solution(vector<int> nums) {
		Elements = nums;
	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		return Elements;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		vector<int> vShuffle = Elements;
		for (int i = 1; i < vShuffle.size(); ++i)
		{
			int r = rand() % (i + 1);
			if (r != i)
			{
				swap(vShuffle[r], vShuffle[i]);
			}
		}
		return vShuffle;
	}

private:
	vector<int> Elements;
};