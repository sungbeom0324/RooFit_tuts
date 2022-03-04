import ROOT


#Set up model
#------------------
#Declare vairiables x, mean, sigma with associated name, title, initial
#value and allowed range
x =  ROOT.RooRealVar("x","x",-10,10)
mean = ROOT.RooRealVar("mean", "mean of gaussian", 1, -10, 10)
sigma = ROOT.RooRealVar("sigma", "width of gaussian", 1, 0.1, 10)

#Build gaussian pdf in terms of x, mean, and sigma
gauss = ROOT.RooGaussian("gauss", "gaussian PDF", x, mean, sigma)

#Construct plot frame in "x"
xframe = x.frame(ROOT.RooFit.Name("xframe"), ROOT.RooFit.Title("RooPlot with decorations")) # RooPlot

#Plot model and change patameter values
#----------------------------------------
#Plot gauss in frame (i.e. in x)
gauss.plotOn(xframe)

#change the value of sigma to 3 
sigma.setVal(3)
gauss.plotOn(xframe, LineColor = "r")

#Generate events 


#Fit model to data & print fitted mean and sigma


# Draw all frames on a canvas
c = ROOT.TCanvas("rf101_basics", "rf101_basics", 800, 400)
xframe.Draw()
