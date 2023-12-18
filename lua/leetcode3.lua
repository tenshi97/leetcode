local bucket = {}
local str = {}
function Clearbucket()
    for i = 0,255 do
    bucket[i]=false;
    end
end
Clearbucket();
local s = io.read();
if(string.len(s)==1) then
    print(1)
    return
end
local ans=0;
local maxans=0;
for i=1,#s do
    ans=0;
    for j =i,#s do
        if(not bucket[string.byte(s,j,j)]) then
            ans=ans+1;
            bucket[string.byte(s,j,j)]=true
            if(j==string.len(s)) then
                Clearbucket();
                if(ans>maxans) then
                    maxans=ans;
                end
            end
        else
            Clearbucket();
            if(ans>maxans)  then
                maxans=ans;
            end
            break;
        end
    end
end
print(maxans)