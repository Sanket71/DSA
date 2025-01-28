in kadane's algo,we have to find maximum subarray sum from given array.

so what is the first thought, brute force , we will run the nested for loop, and we will find the subarray that end at index i, and then traverse that array and find maximum among them that will be maximum subarray sum.

for(i=1;i<=n;i++){\
sum=0;\
t=0;\
for(j=i;j>=1;j--){\
sum=sum+b[j];\
t=max(t,sum);\
}\
prefix[i]=t;\
}

for(i=1;i<=n;i++){\
p1[i]=max(p1[i-1]+b[i],b[i],0)\
}

what is the better solution ?
we make prefix sum array and at each index of that array , we store maximum subarray that end at index i.and then traverse prefix array so we can maximum subarray.

for(i=1;i<=n;i++){\
prefix[i]=max(prefix[i-1]+b[i],b[i],0)\
}

for(i=1;i<=n;i++){\
prefix[i]=max(prefix[i-1]+b[i],b[i],0)\
}

Optimal solution \
instead of using array , use one variable.

T = 0 \
for(i=1;i<=n;i++){ \
current=max(prv+b[i],b[i],0) \
prv=current \
 T=max(T,current) \
}

print(T) = max sum subarray for the whole array
