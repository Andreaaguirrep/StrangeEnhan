#include <iostream>
#include <TFile.h>
#include <TH1.h>
#include <TProfile.h>
#include <TCanvas.h>
#include <TGraph.h>

void ProfileE(){
    gROOT->SetBatch(kTRUE);
   TH1::AddDirectory(kFALSE);
   gROOT->ProcessLine("gErrorIgnoreLevel = kFatal;");
   
    // Open the root files
    TFile *file0a2 = new TFile("GAMMA_0.0_0.2_ON.root");
    TFile *file0a4 = new TFile("GAMMA_0.0_0.4_ON.root");
    TFile *file4a8 = new TFile("GAMMA_0.4_0.8_ON.root");
    
 //MC simulations----------------------------------------------------------------
    
    // Retrieve the TProfiles
//    TProfile *profilep1 = (TProfile*)fileEposLHC->Get("Gammap_pfx");
 //   TProfile *profilep2 = (TProfile*)fileEpos4->Get("Gammap_pfx");
   // TProfile *profilep3 = (TProfile*)filePythia->Get("Gammap_pfx");
    
    TProfile *profilek1 = (TProfile*)file0a2->Get("Gammak_pfx");
    TProfile *profilek2 = (TProfile*)file0a2->Get("Gammak_pfx");
    TProfile *profilek3 = (TProfile*)file0a2->Get("Gammak_pfx");
    
    TProfile *profilel1 = (TProfile*)file0a2->Get("Gammal_pfx");
    TProfile *profilel2 = (TProfile*)file0a2->Get("Gammal_pfx");
    TProfile *profilel3 = (TProfile*)file0a2->Get("Gammal_pfx");
    
    TProfile *profilex1 = (TProfile*)file0a4->Get("Gammax_pfx");
    TProfile *profilex2 = (TProfile*)file0a4->Get("Gammax_pfx");
    TProfile *profilex3 = (TProfile*)file0a4->Get("Gammax_pfx");
    
    TProfile *profileo1 = (TProfile*)file4a8->Get("Gammao_pfx");
    TProfile *profileo2 = (TProfile*)file4a8->Get("Gammao_pfx");
    TProfile *profileo3 = (TProfile*)file4a8->Get("Gammao_pfx");

 //-----------------------------------------------------------------------------
    
    
    
    
    
    TFile *fileHEPp = new TFile("HEPproton.root");
    TFile *fileHEPk = new TFile("HEPk.root");
    TFile *fileHEPl = new TFile("HEPlambda.root");
    TFile *fileHEPx = new TFile("HEPxi.root");
    TFile *fileHEPo = new TFile("HEPomeg.root");
    

    
 //ALICE DATA----------------------------------------------------------------
    
    TGraphErrors* Datak = (TGraphErrors*)fileHEPk->Get("Table 36/Graph1D_y1");
    TGraphErrors* Datalambda = (TGraphErrors*)fileHEPl->Get("Table 37/Graph1D_y1");
    TGraphErrors* Dataxi = (TGraphErrors*)fileHEPx->Get("Table 38/Graph1D_y1");
    TGraphErrors* Dataomega = (TGraphErrors*)fileHEPo->Get("Table 39/Graph1D_y1");
    TGraphErrors* Dataproton = (TGraphErrors*)fileHEPp->Get("Table 47/Graph1D_y1");
    
   // Dataproton->Scale(6.0);   // Scale Dataproton by a factor of 6
    Datalambda->Scale(2.0);   // Scale Datalambda by a factor of 2
    Dataxi->Scale(6.0);       // Scale Dataxi by a factor of 3
    Dataomega->Scale(16.0);    // Scale Dataomega by a factor of 3
   
//----------------------------------------------------------------------------

    // Create a canvas for plotting
    TCanvas *canvas = new TCanvas("canvas", "Histograms and Profiles", 600, 1200);
    
   canvas->SetLogx();
   canvas->SetLogy();
   
   

    
    canvas->cd();
    
  // Create a new pad with specific ranges
    TPad *pad = new TPad("pad", "pad", 0.1, 0.1, 0.9, 0.9);
    pad->SetFillColor(0);
    pad->SetFrameFillColor(0);
    pad->SetBorderMode(0);
    pad->SetBorderSize(0);
    pad->Draw();
    pad->cd();
    pad->SetLogx();
    pad->SetLogy();

    
   Datak->SetLineColor(kBlack); 
   Datak->SetMarkerStyle(kCircle); 

   
   
   Datalambda->SetLineColor(kBlue);
   Datalambda->SetMarkerStyle(kCircle);
   Datalambda->SetMarkerColor(kBlue);
   
   Dataxi->SetLineColor(kGreen); 
   Dataxi->SetMarkerStyle(kCircle);
   Dataxi->SetMarkerColor(kGreen);
   
   Dataomega->SetLineColor(kRed); 
   Dataomega->SetMarkerStyle(kCircle);
   Dataomega->SetMarkerColor(kRed);
   
   //Dataproton->SetLineColorAlpha(kViolet-1,0); 
   //Dataproton->SetMarkerStyle(kCircle);
   //Dataproton->SetMarkerColor(kViolet-1);
   
//TGRAPH-------------------------------------------------------------   
   
   TGraph *gr = new TGraph();

   gr->SetPoint(0, 2, 0.001);
   gr->SetPoint(1, 2, 0.001);
   gr->SetPoint(2,200, 0.2);
   
   

    
    gr->Draw("AP");
    
   gr->SetTitle(" ");
   gr->GetYaxis()->SetTitle("Ratio of yields to (#pi^{+} + #pi^{-})");
   gr->GetXaxis()->SetTitle("#LT dN_{ch}/d#eta #GT_{|#eta|<0.5}");
   gr->GetYaxis()->SetTitleOffset(1.5);
   gr->GetXaxis()->SetTitleOffset(1.5);
   gr->GetYaxis()->CenterTitle();
   gr->GetXaxis()->CenterTitle();
    
//TGRAPH------------------------------------------------------------- 
	
    
    // Redraw the graphs with the updated marker styles
    Datak->Draw("EP same"); // "P" option for drawing markers
    Datalambda->Draw("EP same");
    Datalambda->Draw("EP same");	
    Dataxi->Draw("EP same");
    Dataomega->Draw("EP same");
   // Dataproton->Draw("same");
    
    
    
    
    
// Draw the TProfiles-----------------------------------------
 
    
    //PROTONS---------------------------
    /*
    profilep1->Scale(6.0);
    profilep2->Scale(6.0);
    profilep3->Scale(6.0);


    profilep1->SetMarkerStyle(7);
    profilep1->SetMarkerColor(kViolet);
    profilep1->SetLineColorAlpha(kGreen,0);
   // profilep1->Draw("same");
    
    
    profilep2->SetMarkerStyle(11);
    profilep2->SetMarkerColor(kViolet);
    profilep2->SetLineColorAlpha(kGreen,0);
   // profilep2->Draw("same");
    
    
    profilep3->SetMarkerStyle(5);
    profilep3->SetMarkerColor(kViolet);
    profilep3->SetLineColorAlpha(kGreen,0);
    //profilep3->Draw("same");
    
    */
    //KAONS---------------------------
    profilek1->Scale(2.0);
    profilek2->Scale(2.0);
    profilek3->Scale(2.0);


    profilek1->SetMarkerStyle(7);
    profilek1->SetMarkerColor(kBlack);
    profilek1->SetLineColorAlpha(kGreen,0);
  //  profilek1->Draw("same");
    
    
    profilek2->SetLineColor(kBlack);
    //profilek2->Draw("same");
    
    
    profilek3->SetMarkerStyle(5);
    profilek3->SetMarkerColor(kBlack);
    profilek3->SetLineColorAlpha(kGreen,0);
    profilek3->Draw("same");
    
    
    //LAMBDAS---------------------------
    profilel1->Scale(2.0);
    profilel2->Scale(2.0);
    profilel3->Scale(2.0);


    profilel1->SetMarkerStyle(7);
    profilel1->SetMarkerColor(kBlue);
    profilel1->SetLineColorAlpha(kGreen,0);
    //profilel1->Draw("same");
    
    
    profilel2->SetLineColor(kBlue);
    //profilel2->Draw("same");
    
    
    profilel3->SetMarkerStyle(5);
    profilel3->SetMarkerColor(kBlue);
    profilel3->SetLineColorAlpha(kGreen,0);
    profilel3->Draw("same");
    
    
    //XIS---------------------------
    profilex1->Scale(6.0);
    profilex2->Scale(6.0);
    profilex3->Scale(6.0);


    profilex1->SetMarkerStyle(7);
    profilex1->SetMarkerColor(kGreen);
    profilex1->SetLineColorAlpha(kGreen,0);
   // profilex1->Draw("same");
    
    
    profilex2->SetLineColor(kGreen);
   // profilex2->Draw("same");
    
    
    profilex3->SetMarkerStyle(5);
    profilex3->SetMarkerColor(kGreen);
    profilex3->SetLineColorAlpha(kGreen,0);
    profilex3->Draw("same");
    
    
    //OMEGAS---------------------------
    profileo1->Scale(16.0);
    profileo2->Scale(16.0);
    profileo3->Scale(16.0);


    profileo1->SetMarkerStyle(7);
    profileo1->SetMarkerColor(kRed);
    profileo1->SetLineColorAlpha(kRed,0);
   // profileo1->Draw("same");
    
    
    profileo2->SetLineColor(kRed);
   // profileo2->Draw("same");
    
    
    profileo3->SetMarkerStyle(5);
    profileo3->SetMarkerColor(kRed);
    profileo3->SetLineColorAlpha(kRed,0);
    profileo3->Draw("same");
    
    
    
    
    
//SURFACE/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////PROTONS///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
// Convert TProfile to TGraphErrors to have control over the drawing style
const int np1 = profilep1->GetNbinsX(); // Number of points in the TProfile
double *xp1 = new double[np1];
double *yp1 = new double[np1];
double *exp1 = new double[np1]; // Errors in x (set to 0 if not needed)
double *eyp1 = new double[np1]; // Errors in y

for (int i = 0; i < np1; ++i) {
    // Assuming the x value is the center of the bin
    xp1[i] = profilep1->GetBinCenter(i+1);
    yp1[i] = profilep1->GetBinContent(i+1);
    exp1[i] = 0; // No error in x
    eyp1[i] = profilep1->GetBinError(i+1); // Error in y
}

// Create TGraphErrors with the data from the TProfile
TGraphErrors *grOp1 = new TGraphErrors(np1, xp1, yp1, exp1, eyp1);
grOp1->SetFillColorAlpha(kViolet,0.3); // Set fill color to red
grOp1->SetLineColorAlpha(kBlue,0); // Set line color to red
grOp1->SetFillStyle(1001); // Solid fill style

// Draw the graph with error bars and a smooth colored surface
grOp1->Draw("3"); // "3" option to draw a smooth surface


// Convert TProfile to TGraphErrors to have control over the drawing style
const int np2 = profilep2->GetNbinsX(); // Number of points in the TProfile
double *xp2 = new double[np2];
double *yp2 = new double[np2];
double *exp2 = new double[np2]; // Errors in x (set to 0 if not needed)
double *eyp2 = new double[np2]; // Errors in y

for (int i = 0; i < np2; ++i) {
    // Assuming the x value is the center of the bin
    xp2[i] = profilep2->GetBinCenter(i+1);
    yp2[i] = profilep2->GetBinContent(i+1);
    exp2[i] = 0; // No error in x
    eyp2[i] = profilep2->GetBinError(i+1); // Error in y
}

// Create TGraphErrors with the data from the TProfile
TGraphErrors *grOp2 = new TGraphErrors(np2, xp2, yp2, exp2, eyp2);
grOp2->SetFillColorAlpha(kViolet,0.3); // Set fill color to red
grOp2->SetLineColorAlpha(kBlue,0); // Set line color to red
grOp2->SetFillStyle(1001); // Solid fill style

// Draw the graph with error bars and a smooth colored surface
grOp2->Draw("3"); // "3" option to draw a smooth surface


// Convert TProfile to TGraphErrors to have control over the drawing style
const int np3 = profilep3->GetNbinsX(); // Number of points in the TProfile
double *xp3 = new double[np3];
double *yp3 = new double[np3];
double *exp3 = new double[np3]; // Errors in x (set to 0 if not needed)
double *eyp3 = new double[np3]; // Errors in y

for (int i = 0; i < np3; ++i) {
    // Assuming the x value is the center of the bin
    xp3[i] = profilep3->GetBinCenter(i+1);
    yp3[i] = profilep3->GetBinContent(i+1);
    exp3[i] = 0; // No error in x
    eyp3[i] = profilep3->GetBinError(i+1); // Error in y
}

// Create TGraphErrors with the data from the TProfile
TGraphErrors *grOp3 = new TGraphErrors(np3, xp3, yp3, exp3, eyp3);
grOp3->SetFillColorAlpha(kViolet,0.3); // Set fill color to red
grOp3->SetLineColorAlpha(kBlue,0); // Set line color to red
grOp3->SetFillStyle(1001); // Solid fill style

// Draw the graph with error bars and a smooth colored surface
grOp3->Draw("3"); // "3" option to draw a smooth surface
*/
////KAONES///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Convert TProfile to TGraphErrors to have control over the drawing style
const int nk1 = profilek1->GetNbinsX(); // Number of points in the TProfile
double *xk1 = new double[nk1];
double *yk1 = new double[nk1];
double *exk1 = new double[nk1]; // Errors in x (set to 0 if not needed)
double *eyk1 = new double[nk1]; // Errors in y

for (int i = 0; i < nk1; ++i) {
    // Assuming the x value is the center of the bin
    xk1[i] = profilek1->GetBinCenter(i+1);
    yk1[i] = profilek1->GetBinContent(i+1);
    exk1[i] = 0; // No error in x
    eyk1[i] = profilek1->GetBinError(i+1); // Error in y
}

// Create TGraphErrors with the data from the TProfile
TGraphErrors *grOk1 = new TGraphErrors(nk1, xk1, yk1, exk1, eyk1);
grOk1->SetFillColorAlpha(kBlack,0.3); // Set fill color to red
grOk1->SetLineColorAlpha(kBlue,0); // Set line color to red
grOk1->SetFillStyle(1001); // Solid fill style

// Draw the graph with error bars and a smooth colored surface
//grOk1->Draw("3"); // "3" option to draw a smooth surface

// Convert TProfile to TGraphErrors to have control over the drawing style
const int nk3 = profilek3->GetNbinsX(); // Number of points in the TProfile
double *xk3 = new double[nk3];
double *yk3 = new double[nk3];
double *exk3 = new double[nk3]; // Errors in x (set to 0 if not needed)
double *eyk3 = new double[nk3]; // Errors in y

for (int i = 0; i < nk3; ++i) {
    // Assuming the x value is the center of the bin
    xk3[i] = profilek3->GetBinCenter(i+1);
    yk3[i] = profilek3->GetBinContent(i+1);
    exk3[i] = 0; // No error in x
    eyk3[i] = profilek3->GetBinError(i+1); // Error in y
}

// Create TGraphErrors with the data from the TProfile
TGraphErrors *grOk3 = new TGraphErrors(nk3, xk3, yk3, exk3, eyk3);
grOk3->SetFillColorAlpha(kBlack,0.3); // Set fill color to red
grOk3->SetLineColorAlpha(kBlue,0); // Set line color to red
grOk3->SetFillStyle(1001); // Solid fill style

// Draw the graph with error bars and a smooth colored surface
grOk3->Draw("3"); // "3" option to draw a smooth surface


////LAMBDAS///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Convert TProfile to TGraphErrors to have control over the drawing style
const int nl1 = profilel1->GetNbinsX(); // Number of points in the TProfile
double *xl1 = new double[nl1];
double *yl1 = new double[nl1];
double *exl1 = new double[nl1]; // Errors in x (set to 0 if not needed)
double *eyl1 = new double[nl1]; // Errors in y

for (int i = 0; i < nl1; ++i) {
    // Assuming the x value is the center of the bin
    xl1[i] = profilel1->GetBinCenter(i+1);
    yl1[i] = profilel1->GetBinContent(i+1);
    exl1[i] = 0; // No error in x
    eyl1[i] = profilel1->GetBinError(i+1); // Error in y
}

// Create TGraphErrors with the data from the TProfile
TGraphErrors *grOl1 = new TGraphErrors(nl1, xl1, yl1, exl1, eyl1);
grOl1->SetFillColorAlpha(kBlue,0.3); // Set fill color to red
grOl1->SetLineColorAlpha(kBlue,0); // Set line color to red
grOl1->SetFillStyle(1001); // Solid fill style

// Draw the graph with error bars and a smooth colored surface
//grOl1->Draw("3"); // "3" option to draw a smooth surface

// Convert TProfile to TGraphErrors to have control over the drawing style
const int nl3 = profilel3->GetNbinsX(); // Number of points in the TProfile
double *xl3 = new double[nl3];
double *yl3 = new double[nl3];
double *exl3 = new double[nl3]; // Errors in x (set to 0 if not needed)
double *eyl3 = new double[nl3]; // Errors in y

for (int i = 0; i < nl3; ++i) {
    // Assuming the x value is the center of the bin
    xl3[i] = profilel3->GetBinCenter(i+1);
    yl3[i] = profilel3->GetBinContent(i+1);
    exl3[i] = 0; // No error in x
    eyl3[i] = profilel3->GetBinError(i+1); // Error in y
}

// Create TGraphErrors with the data from the TProfile
TGraphErrors *grOl3 = new TGraphErrors(nl3, xl3, yl3, exl3, eyl3);
grOl3->SetFillColorAlpha(kBlue,0.3); // Set fill color to red
grOl3->SetLineColorAlpha(kBlue,0); // Set line color to red
grOl3->SetFillStyle(1001); // Solid fill style

// Draw the graph with error bars and a smooth colored surface
grOl3->Draw("3"); // "3" option to draw a smooth surface

////XIS///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Convert TProfile to TGraphErrors to have control over the drawing style
const int nx1 = profilex1->GetNbinsX(); // Number of points in the TProfile
double *xx1 = new double[nx1];
double *yx1 = new double[nx1];
double *exx1 = new double[nx1]; // Errors in x (set to 0 if not needed)
double *eyx1 = new double[nx1]; // Errors in y

for (int i = 0; i < nx1; ++i) {
    // Assuming the x value is the center of the bin
    xx1[i] = profilex1->GetBinCenter(i+1);
    yx1[i] = profilex1->GetBinContent(i+1);
    exx1[i] = 0; // No error in x
    eyx1[i] = profilex1->GetBinError(i+1); // Error in y
}

// Create TGraphErrors with the data from the TProfile
TGraphErrors *grOx1 = new TGraphErrors(nx1, xx1, yx1, exx1, eyx1);
grOx1->SetFillColorAlpha(kGreen,0.3); // Set fill color to red
grOx1->SetLineColorAlpha(kGreen,0); // Set line color to red
grOx1->SetFillStyle(1001); // Solid fill style

// Draw the graph with error bars and a smooth colored surface
//grOx1->Draw("3"); // "3" option to draw a smooth surface

// Convert TProfile to TGraphErrors to have control over the drawing style
const int nx3 = profilex3->GetNbinsX(); // Number of points in the TProfile
double *xx3 = new double[nx3];
double *yx3 = new double[nx3];
double *exx3 = new double[nx3]; // Errors in x (set to 0 if not needed)
double *eyx3 = new double[nx3]; // Errors in y

for (int i = 0; i < nx3; ++i) {
    // Assuming the x value is the center of the bin
    xx3[i] = profilex3->GetBinCenter(i+1);
    yx3[i] = profilex3->GetBinContent(i+1);
    exx3[i] = 0; // No error in x
    eyx3[i] = profilex3->GetBinError(i+1); // Error in y
}

// Create TGraphErrors with the data from the TProfile
TGraphErrors *grOx3 = new TGraphErrors(nx3, xx3, yx3, exx3, eyx3);
grOx3->SetFillColorAlpha(kGreen,0.3); // Set fill color to red
grOx3->SetLineColorAlpha(kGreen,0); // Set line color to red
grOx3->SetFillStyle(1001); // Solid fill style

// Draw the graph with error bars and a smooth colored surface
grOx3->Draw("3"); // "3" option to draw a smooth surface


////OMEGAS///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Convert TProfile to TGraphErrors to have control over the drawing style
const int n = profileo1->GetNbinsX(); // Number of points in the TProfile
double *x = new double[n];
double *y = new double[n];
double *ex = new double[n]; // Errors in x (set to 0 if not needed)
double *ey = new double[n]; // Errors in y

for (int i = 0; i < n; ++i) {
    // Assuming the x value is the center of the bin
    x[i] = profileo1->GetBinCenter(i+1);
    y[i] = profileo1->GetBinContent(i+1);
    ex[i] = 0; // No error in x
    ey[i] = profileo1->GetBinError(i+1); // Error in y
}

// Create TGraphErrors with the data from the TProfile
TGraphErrors *grO1 = new TGraphErrors(n, x, y, ex, ey);
grO1->SetFillColorAlpha(kRed,0.3); // Set fill color to red
grO1->SetLineColorAlpha(kRed,0); // Set line color to red
grO1->SetFillStyle(1001); // Solid fill style

// Draw the graph with error bars and a smooth colored surface
//grO1->Draw("3"); // "3" option to draw a smooth surface

// Convert TProfile to TGraphErrors to have control over the drawing style
const int n3 = profileo3->GetNbinsX(); // Number of points in the TProfile
double *x3 = new double[n];
double *y3 = new double[n];
double *ex3 = new double[n]; // Errors in x (set to 0 if not needed)
double *ey3 = new double[n]; // Errors in y

for (int i = 0; i < n3; ++i) {
    // Assuming the x value is the center of the bin
    x3[i] = profileo3->GetBinCenter(i+1);
    y3[i] = profileo3->GetBinContent(i+1);
    ex3[i] = 0; // No error in x
    ey3[i] = profileo3->GetBinError(i+1); // Error in y
}

// Create TGraphErrors with the data from the TProfile
TGraphErrors *grO3 = new TGraphErrors(n3, x3, y3, ex3, ey3);
grO3->SetFillColorAlpha(kRed,0.3); // Set fill color to red
grO3->SetLineColorAlpha(kRed,0); // Set line color to red
grO3->SetFillStyle(1001); // Solid fill style

// Draw the graph with error bars and a smooth colored surface
grO3->Draw("3"); // "3" option to draw a smooth surface



    
    
    
    
//----------------------------------------------------------------
    
    TLegend* legend = new TLegend(0.6, 0.5, 0.9	, 0.8); // (x1, y1, x2, y2) coordinates for the legend
   legend->SetHeader("ALICE DATA");
  // legend->AddEntry(Dataproton, "p + #bar{p} (x6)", "p");
   legend->AddEntry(Datak, "2K^{0}_{s}", "p");	
   legend->AddEntry(Datalambda, "#Lambda + #bar{#Lambda} (x2)", "p");
   legend->AddEntry(Dataxi, "#Xi^{-} + #bar{#Xi^{+}} (x6)", "p");
   legend->AddEntry(Dataomega, "#Omega^{-} + #bar{#Omega^{+}} (x16)", "p");
   legend->SetBorderSize(0);
   legend->SetFillColorAlpha(0, 0); // Transparent fill color
   
   legend->Draw("same");
   
   
   TLegend* legend1 = new TLegend(0.6, 0.2, 0.9	, 0.5); // (x1, y1, x2, y2) coordinates for the legend
   legend1->SetHeader("EPOS-LHC, FUSION ON");
   legend1->AddEntry(profilek3, "0 < b < 0.2", "p");
   legend1->AddEntry(profilel3, "0 < b < 0.2", "p");
   legend1->AddEntry(profilex3, "0 < b < 0.4", "p");
   legend1->AddEntry(profileo3, "0.4 < b < 0.8	", "p");
   legend1->SetBorderSize(0);
   legend1->SetFillColorAlpha(0, 0); // Transparent fill color
   legend1->SetTextSize(0.025); 
   
   legend1->Draw("same");
  
   
   //canvas->SaveAs("MBOFF.pdf");
    //canvas->SaveAs("b1.3eraopcion.pdf");
    canvas->SaveAs("best1E.pdf");
    
    


   
}


