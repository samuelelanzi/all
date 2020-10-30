void perrin() {
    TGraph *graph = new TGraph("data.txt","%lg %lg"); 
    graph -> SetTitle("Esperimento ; t [s] ; x(t) [m]");

    graph -> SetMarkerStyle(kOpenCircle);
    graph -> SetMarkerColor(kBlue);
    graph -> SetLineColor(kBlue);

    TCanvas *mycanvas = new TCanvas();

    TF1 *f = new TF1("Quadratic Law", "x * x * [0]", 0.0, 0.9);

    f -> SetLineColor(kRed); 
    f -> SetLineStyle(2);
 
    graph -> Fit(f);
 
    gStyle -> SetOptFit(111);
    graph -> Draw("APE");
}
