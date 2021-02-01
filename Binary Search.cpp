int Binary_Search(vector<int>& nums, int target) {

    int l = 0, r = nums.size() - 1, mean_index = (r + l) / 2 ;
	
	// while r pointer is greater than left pointer, this means that the wanted target is still between l & r.
	// if this condition failed to satisfy, this means that the target isn't in the sorted list, value of -1 will be returned
    while (r >= l)
    {
        // every time calculate the index of the new mean
        mean_index = (r + l) / 2;

		// if the target bigger than mean value move l to mean+1
        if (target > nums[mean_index])
        {
            l = mean_index + 1;
        }
		
		// if the target less than mean value move r to mean-1
        else if (target < nums[mean_index])
        {
            r = mean_index - 1;
        }
		
		// if the target isn't bigger or smaller than the mean value, then it's the mean value itself
        else
            return mean_index;
    }
	
	// if the target is not found return -1
    return -1;
}
