//rf101_basics.C
//ROOFIT 으로 Gaussian pdf Ploting 과 Data Fitting

#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooGaussian.h"
#include "TCanvas.h"
#include "RooPlot.h"
#include "TAxis.h"
using namespace RooFit;

void rf101_basics()
{
  // Setup Model 
  //------------------

  //Declare variables x, mean, sigma with associated name, title, initial value with allowed range
  RooRealVar x("x", "x", -10, 10);
  RooRealVar mean("mean", "mean of gaussian", 1, -10, 10);
  RooRealVar sigma("sigma", "width of gaussian", 1, 0.1, 10);

  //Build gaussian pdf in terms of x,mean and sigma
  RooGaussian gauss("gauss", "gaussian PDF", x, mean, sigma);

  //Construct plot frame in 'x'
  RooPlot *xframe = x.frame(Title("Gaussian pdf."));

  //Plot model and change parameter values
  //---------------------------------------------
 
  //Plot gauss in franme (i.e. in x)
  gauss.plotOn(xframe);

  //Change the value of sigma to 3
  sigma.setVal(3);
  
  //Plot gauss in frame (i.e. in x) and draw frame on canvas 
  gauss.plotOn(xframe, LineColor(kRed));


/*
  //Generate events
  //------------------
  
  //Generate a dataset of 1000 events in x from gauss
  RooDataSet *data = gauss.generate(x, 10000);
  
  //Make a second plot frame in x 
  //and draw both the "data" & "pdf" in the frame
  RooPlot *xframe2 = x.frame(Title("Gaussian pdf with data"));
  data -> Ploton(xframe2);
  gauss.plotOn(xframe2);    
   
  //Fit model to data
  //------------------
  
  //Fit pdf to data
  gauss.fitTo(*data);

  // Print values of mean and sigma (that now reflect fitted walues and errors!!!)
  mean.Print();
  sigma.Print();
*/

  //Draw all frames on a canvas
  TCanvas *c = new TCanvas("rf101_basics", "rf101_basics", 800, 400);
//  xframe -> GetYaxis() -> SetTitleOffset(1.6);
  xframe -> Draw();  
}

/*
[A] 데이터 없이 하는 경우 (PLOT)
1. RooRwalVar, RooGaussian 으로 피팅 함수를 정의한다.
2. RooPlot 으로(원하는 변수에 대한) frame 을 만든다. frame 이 함수가 그려지게되는 필름인듯.
4. gauss.plotOn(xframe) 으로 frame 에 함수를 plot 한다. 즉 그림 완성
3. TCanvas 에 frame 을 Draw 한다. 즉 그림을 캔버스 위에 실체화 하는 것.

[B] 실험 데이터가 있는 경우 (FIT)
[A] + 
1. RooDataSet 으로 데이터셋 만든다.
2. frmae2 를 만들고 데이터와 함수를 plotOn 한다. !!Fit 을 먼저하지 않는다.
3. fitTo(*data) 를 통해 함수를 피팅한다. 그 결과 init mean, std 가 바뀌는 것인데 이 결과를
4. mean.Print() 과 sigma.Print() 를 통해 확인할 수 있다. 

[C] 위의 [A] 와 [B] 를 하나의 TCanvas 에 올리기 위해 잘 파티션 한다.
*/
