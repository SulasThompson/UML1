

{

  cout << "hello!" << endl;


  TFile *infile = TFile::Open("Species.root");
  TTree *tree   = (TTree*)infile->Get("species");

  tree->Print();

  int    id;
  double t;
  double sumG;

  tree->SetBranchAddress("speciesID",&id);
  tree->SetBranchAddress("time",&t);
  tree->SetBranchAddress("sumG",&sumG);


  std::vector<int>    idVec;
  std::vector<double> tVec;
  std::vector<double> sumGVec;
 

  for(long x=0;x<tree->GetEntries();x++) {
    tree->GetEntry(x);
    //here we process
    idVec.push_back(id);
    tVec.push_back(t);
    sumGVec.push_back(sumG);
  }


  
  TGraph *gr[7]= {0};
  
  //ofstream ofile;
  //ofile.open("mydata.dat");
  for(int i=0;i<tVec.size();i++) {
    //ofile << idVec.at(i) << "\t" << tVec.at(i) << "\t" << sumGVec.at(i) << endl;
    if(!gr[idVec.at(i)])
      gr[idVec.at(i)] = new TGraph;
    gr[idVec.at(i)]->AddPoint(tVec[i],sumGVec[i]);
  }
  //ofile.close();

  TCanvas *c = new TCanvas;
  c->Divide(4,2);
  for(int i=0;i<7;i++) {
    c->cd(i+1);
    gPad->SetLogx();
    gr[i]->Draw("A*");
    gr[i]->SetTitle(Form("id = %i",i));
  }




  
  //TGraph *gr = new TGraph(tVec.size(),tVec.data(),sumGVec.data());
  //gr->Draw("A*");


}
