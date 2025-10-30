def in_area(x,y):
    yp2=(y-0.575)*(y-0.575)
    xp2=(x-0.635)*(x-0.635)
    xp3=xp2*(x-0.635)
    p3a=(yp2+xp2-0.2)
    p3=p3a*p3a*p3a
    ans=p3+yp2*xp3
    return (ans<=0)

n=40
prec=1.15/n
for x in range(0,n+1):
    for y in range(0,n+1):
        xx=prec*x
        yy=prec*y
        if in_area(xx,yy):
            print(" M ",end="")
        else:
            print("     ",end="")
    print("\n",end="")

while 1:
    pass
