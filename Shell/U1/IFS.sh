#IFS默认为空格,下面将其设置为了逗号

oldIFS=$IFS
s="sdfd,df,gg,kkk,jjj"
IFS=","
for i in $s
    do
    echo $i
done

IFS=$oldIFS