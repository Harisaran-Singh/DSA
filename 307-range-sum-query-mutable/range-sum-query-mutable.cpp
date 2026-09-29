class NumArray {
public:
        vector<int> seg;
        void SGTree(int n){
            seg.resize(4*n);
        }
        void build(int ind,int low, int high,vector<int>& nums){
            if(high==low){
                seg[ind] = nums[low];
                return;
            }
            int mid = low+(high-low)/2;
            build(2*ind+1,low,mid,nums);
            build(2*ind+2,mid+1,high,nums);
            seg[ind] = seg[2*ind+1]+seg[2*ind+2];
        }
        void modify(int ind,int low, int high,int idx,int val){
            if(low==high){
                seg[ind] = val;
                return;
            }
            int mid = low+(high-low)/2;
            if(idx<=mid) modify(2*ind+1,low,mid,idx,val);
            else modify(2*ind+2,mid+1,high,idx,val);
            seg[ind] = seg[2*ind+1]+seg[2*ind+2];
        }
        int query(int ind,int low,int high,int l,int r){
            if(r<low || high<l) return 0;
            if(l<=low && high<=r) return seg[ind];
            int mid = low+(high-low)/2;
            int left = query(2*ind+1,low,mid,l,r);
            int right = query(2*ind+2,mid+1,high,l,r);
            return left+right;
        }
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size();
        SGTree(n);
        build(0,0,n-1,nums);
    }
    
    void update(int index, int val) {
        modify(0,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        return query(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */