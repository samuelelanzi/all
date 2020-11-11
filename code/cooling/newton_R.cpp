void run()
{
    TGraph *graph = new TGraph("Raffreddamento.txt","%lg %lg"); 
    graph -> SetTitle("Legge Raffreddamento; t [s] ; T(t) [C]");
    graph -> SetLineColor(kBlue);
    TCanvas *mycanvas = new TCanvas();
    graph -> Draw();
    mycanvas->Print("Raffreddamento.pdf");
}
