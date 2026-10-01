var minOperations = function(nums1, nums2, k) {
    
    let count = 0, balance = 0;
    
    for(let i = 0; i < nums1.length; i++) {
        
        const diff = nums1[i] - nums2[i];
        
        if(diff % k) return -1;
        
        if(k === 0 && diff !== 0) return -1;
        
        count += diff > 0 ? diff / k : 0;
        balance += diff;
    }
    
    return balance === 0 ? count : -1;
};