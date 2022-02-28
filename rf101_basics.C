//rf101_basics.C
//ROOFIT 으로 Gaussian pdf Ploting

#include "RooRealVar.h"
#include "RooDataSet.h"
#include "GooGaussian.h"
#include "TCanvas.h"
#include "RooPlot.h"
#include "TAxis.h"
using namespace RooFit;

void rf101_basics()
{
  // Setup Model 
  //------------------

  //Declare variables x, mean, sigma with associated name, title, initial value with allowed range
  RooRealVar x("x", "x", 10, 10);
  RooRealVar mean("mean", "mean of gaussian", 1, -10, 10);
  RooRealVar sigma("sigma", "width of gaussian", 1, 0.1, 10);

  //Build gaussian pdf in terms od x,mean and sigma
  RooGaussian gauss("gauss", "gaussian PDF", x, mean, sigma);

  //Construct plot frame in 'x'
  RooPlot *xframe = x.frame(Title("Gaussian pdf."));




}
