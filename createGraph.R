#postscript(family="Times", 'multi.ps', width=40)
#pdf(family="Times", 'multi.pdf', width=40)
rawData <- file("stdin")

# draw points (offsets is for color)
offsets   <- c(0.0, 0.3, 0.3, 0.6, 0.6)
linethick <- c(0.5, 0.5, 0.5, 1.5, 1.5)
# leg.txt   <- c(
#         "actual p(novel)", 
#         "p'(novel), mehtod X",
#         "p'(novel), method X+stdev", 
#         "p'(novel), method X-fac",
#         "p'(novel), method X-fac+stdev ")


#read source file
data1 <- read.csv(rawData, header=TRUE)
data <- data1
# data <- subset(data1, iteration%%20 == 0 || iteration < 500)
	#col.names=c("vx1","vy1","vy2","vy3","vy4","vy5","vy6","vy7")
    

    #cbind() forms matrices by binding together matrices horizontally, 
    #or column-wise, and rbind() vertically, or row-wise
line1node <- cbind(data[, c(1)], data[,c(2)])
    #draw line1, xaxt="n" means not draw x axis now; 
    # lty=1 means solid line, lwd means line width
# plot(data[,1], data[,2], main="Strategies", xlab="Iteration", ylab="Alpha", pch=10)

par(pch=22, col="black") # plotting symbol and color
par(mfrow=c(3,4)) # all plots on one page
# opts = c("p","l","o","b","c","s","S","h")
for(i in 2:11){
  heading = paste("firm =",i-1)
  plot(data[,1], data[,i], type="n", main=heading, xlab="Iteration", ylab="Alpha")
  lines(data[,1], data[,i], type="c")
}

data1

    # 1 means draw ticks on the bottom. At determines place making a tick
# axis(1, at=c(10,100,500,1000,10000,20000,30000,40000,50000), font.axis=6 )
    # 2 means draw ticks on the left. 
# axis(2, at=c(0,0.1,0.2,0.3,0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0) , font.axis=6 )

    #draw line 2. lty=3 means dotted
# line2node <- cbind(data$vx1, data$vy2)
# lines(line2node, type="l", col=gray(offsets[2]), lty=3, lwd=linethick[2]);

#     # remove those rows if vy3 values above 1 and assign those
#     # satisfied rows to line3smallnode
# line3smallnode <- subset( data, !(vy3 > 1) )
#     # draw line3. lty=2 means dashed
# line3node <- cbind(line3smallnode$vx1, line3smallnode$vy3)
# lines(line3node, type="l", col=gray(offsets[3]), lty=2, lwd=linethick[3]);

#     # draw line4. lty=2 means dashed
# line4node <- cbind(data$vx1, data$vy5)
# lines(line4node, type="l", col=gray(offsets[4]), lty=1, lwd=linethick[4]);

#     # draw line5. (lty=2 == lty="dashed")
# lines(data$vx1, data$vy6, type="l", 
#       col=gray(offsets[5]), lty="dashed", lwd=linethick[5]);

#     # 10,0.7 is the position of legend. leg.txt is each line title. 
#     # bty="n" remove the box around legend 
#     # cex=0.9 means legend is 0.9 time of current font size
# legend(10,0.7, leg.txt, lty = c(1,3,2,1,2), 
#        col = gray(offsets),lwd=linethick, bty="n", cex = 0.9) 

# pdf("1.pdf")

#dev.off()  # This is only needed if you use pdf/postscript in interactive mode
