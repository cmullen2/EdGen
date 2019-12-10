Double_t E0=11;
Double_t Mp=0.93821;
Double_t Me=0.511e-3;
Double_t gamma_v;
Double_t eps;

Double_t Vomega_thetae(Double_t *x,Double_t *p){
  // Double_t E0=p[0];
  Double_t omega=x[0];//=Egamma
  Double_t Eeprime=E0-x[0];
  Double_t Peprime=sqrt(Eeprime*Eeprime-0.511e-3*0.511e-3);
  Double_t Q2=4*E0*Eeprime*sin(x[1]/2)*sin(x[1]/2);//x[1]=thetae
  Double_t psi=TMath::ACos((Q2+2*E0*omega)/(2*E0*sqrt(Q2+omega*omega)));
  Double_t W=Mp*Mp+2*Mp*omega-Q2;
  if(W<0) return 0;
  else W=sqrt(W);
  eps=1./(1+2*(1+omega*omega/Q2)*TMath::Tan(x[1]/2)*TMath::Tan(x[1]/2));
  gamma_v=(1./137/2/TMath::Pi()*TMath::Pi())*(Eeprime/E0)*((W*W-Mp*Mp)/2/Mp)/Q2/(1-eps)*TMath::Sin(x[1]);//*TMath::Sin(psi);
  //if(gamma_v<0)cout<<omega<<" x[1] "<<x[1]<<" Eeprime "<<Eeprime<<" Peprime "<<Peprime<<" Q2 "<<Q2<<" psi "<<psi<<" W "<<W<<" eps "<<eps<<" gamma_v "<<gamma_v<<endl;
  if(gamma_v<0)return 0;
  return gamma_v;
}
TLorentzVector* e0=new TLorentzVector(0,0,sqrt(E0*E0-Me*Me),E0);
TLorentzVector* ep=new TLorentzVector(0,0,sqrt(E0*E0-Me*Me),E0);
TLorentzVector* gamma=new TLorentzVector();

Double_t VEe_thetae(Double_t *x,Double_t *p){
  // Double_t E0=p[0];
  Double_t the=x[1]*TMath::DegToRad();
  Double_t Eeprime=x[0];
  Double_t omega=E0-Eeprime;//=Egamma
  Double_t Peprime=sqrt(Eeprime*Eeprime-0.511e-3*0.511e-3);
  Double_t Q2=4*E0*Eeprime*sin(the/2)*sin(the/2);//x[1]=thetae
  Double_t psi=TMath::ACos((Q2+2*E0*omega)/(2*E0*sqrt(Q2+omega*omega)));
  Double_t W=Mp*Mp+2*Mp*omega-Q2;
  //cout<<" W "<<W<< " Eeprime "<<Eeprime<<" theta "<<x[1]*TMath::RadToDeg()<<endl;
  ep->SetE(Eeprime);
  ep->SetRho(Peprime);
  ep->SetTheta(the);
  *gamma=*e0-*ep;
  // cout<<"theta g "<<psi<<" "<< gamma->Theta()<<endl;
  if(W<0) return 0;
  else W=sqrt(W);
  eps=1./(1+2*(1+omega*omega/Q2)*TMath::Tan(the/2)*TMath::Tan(the/2));
  // gamma_v=(1./137/2/TMath::Pi()*TMath::Pi())*(Eeprime/E0)*((W*W-Mp*Mp)/2/Mp)/Q2/(1-eps)*TMath::Sin(x[1]);//*TMath::Sin(psi);
  gamma_v=(1./137/4/TMath::Pi())*((W*W-Mp*Mp)/omega/omega/Mp/Mp)*W/Q2/(1-eps)*TMath::Sin(the);//*TMath::Sin(psi);
  //gamma_v=1*TMath::Sin(x[1])*TMath::Sin(psi);
  //   cout<<omega<<" x[1] "<<x[1]<<" Eeprime "<<Eeprime<<" Peprime "<<Peprime<<" Q2 "<<Q2<<" psi "<<psi<<" W "<<W<<" eps "<<eps<<" gamma_v "<<gamma_v<<endl;
  if(gamma_v<0)return 0;
  return gamma_v;
}
Double_t SigmaEe_thetae(Double_t *x,Double_t *p){
  // Double_t E0=p[0];
  Double_t Eeprime=x[0];
  Double_t the=x[1]*TMath::DegToRad();
  Double_t omega=E0-Eeprime;//=Egamma
  Double_t Peprime=sqrt(Eeprime*Eeprime-0.511e-3*0.511e-3);
  Double_t Q2=4*E0*Eeprime*sin(the/2)*sin(the/2);//x[1]=thetae
  Double_t psi=TMath::ACos((Q2+2*E0*omega)/(2*E0*sqrt(Q2+omega*omega)));
  Double_t W=Mp*Mp+2*Mp*omega-Q2;
  ep->SetE(Eeprime);
  ep->SetRho(Peprime);
  ep->SetTheta(the);
  *gamma=*e0-*ep;
  //cout<<"theta g "<<psi<<" "<< gamma->Theta()<<" "<<Q2<<" "<<gamma->M2()endl;
  if(W<0) return 0;
  else W=sqrt(W);
  eps=1./(1+2*(1+omega*omega/Q2)*TMath::Tan(the/2)*TMath::Tan(the/2));
  //gamma_v=(1./137/2/TMath::Pi()*TMath::Pi())*(Eeprime/E0)*((W*W-Mp*Mp)/2/Mp)/Q2/(1-eps)*TMath::Sin(the);
  Double_t sin2th2=TMath::Sin(the/2)*TMath::Sin(the/2);
  //Double_t gamma_v3=(1./137/4/TMath::Pi()/TMath::Pi()/omega)*((E0*E0+Eeprime*Eeprime)/2/E0/E0/(Me*Me*omega*omega/4/E0/E0/Eeprime/Eeprime+sin2th2)-Eeprime/E0*Me*Me*omega*omega/4/E0/E0/Eeprime/Eeprime/(Me*Me*omega*omega/4/E0/E0/Eeprime/Eeprime+sin2th2)/(Me*Me*omega*omega/4/E0/E0/Eeprime/Eeprime+sin2th2)-(E0+Eeprime)*(E0+Eeprime)/4/Eeprime/Eeprime/(omega*omega/4/E0/Eeprime+sin2th2));
  Double_t gamma_v=(1./137/4/TMath::Pi()/TMath::Pi())/E0*Eeprime*(W*W-Mp*Mp)/Mp/Q2/(1-eps);
  // Double_t gamma_v2=(1./137/4/TMath::Pi()/TMath::Pi())*omega/Q2/E0*Eeprime*2/(1-eps);
  // cout<<"Gammav "<<gamma_v<<" "<<gamma_v3*TMath::Sin(the)<<" "<<gamma_v2*TMath::Sin(the)<<endl;
//*TMath::Sin(psi);
  //gamma_v=1*TMath::Sin(x[1])*TMath::Sin(psi);
  if(gamma_v<0)return 0;
  //Double_t sigma=gamma_v / (1+Q2/.7/.7)/ (1+Q2/.7/.7)*TMath::Sin(the);
  Double_t sigma=130*TMath::Sin(the)*gamma_v/ (1+Q2/.7/.7)/ (1+Q2/.7/.7);
  //Double_t sigma=0.001*TMath::Sin(the)*gamma_v/ (1+Q2/.7/.7)/ (1+Q2/.7/.7);//1nb
  //Double_t sigma=15.E-33*TMath::Sin(the)*gamma_v / (1+Q2/.7/.7)/ (1+Q2/.7/.7);
  //cout<<omega<<" x[1] "<<the*TMath::RadToDeg()<<" Eeprime "<<Eeprime<<" Peprime "<<Peprime<<" Q2 "<<Q2<<" psi "<<psi<<" W "<<W<<" eps "<<eps<<" gamma_v "<<gamma_v<<" "<<sigma<<endl;
  return sigma;
}
Double_t VElastic_thetae(Double_t *x,Double_t *p){
  Double_t thetae=x[0]*TMath::DegToRad();
  Double_t Eeprime=Mp*E0/(2*E0*TMath::Sin(thetae/2)*TMath::Sin(thetae/2)+Mp);
  return Eeprime;
  //if(x[0]!=Eeprime)return 0;
  Double_t omega=E0-Eeprime;//=Egamma
  Double_t Peprime=sqrt(Eeprime*Eeprime-0.511e-3*0.511e-3);
  Double_t Q2=4*E0*Eeprime*sin(thetae/2)*sin(thetae/2);//x[1]=thetae
  Double_t psi=TMath::ACos((Q2+2*E0*omega)/(2*E0*sqrt(Q2+omega*omega)));
  Double_t W=Mp*Mp+2*Mp*omega-Q2;
  //cout<<" W "<<W<< " Eeprime "<<Eeprime<<" theta "<<x[0]*TMath::RadToDeg()<<endl;
  ep->SetE(Eeprime);
  ep->SetRho(Peprime);
  ep->SetTheta(thetae);
  *gamma=*e0-*ep;
  // cout<<"theta g "<<psi<<" "<< gamma->Theta()<<endl;
  if(W<0) return 0;
  else W=sqrt(W);
  eps=1./(1+2*(1+omega*omega/Q2)*TMath::Tan(thetae/2)*TMath::Tan(thetae/2));
  gamma_v=(1./137/2/TMath::Pi()*TMath::Pi())*(Eeprime/E0)*((W*W-Mp*Mp)/2/Mp)/Q2/(1-eps)*TMath::Sin(thetae);//*TMath::Sin(psi);
  //gamma_v=1*TMath::Sin(x[1])*TMath::Sin(psi);
  cout<<omega<<" thetae "<<thetae*TMath::RadToDeg()<<" Eeprime "<<Eeprime<<" Peprime "<<Peprime<<" Q2 "<<Q2<<" psi "<<psi<<" W "<<W<<" eps "<<eps<<" gamma_v "<<gamma_v<<endl;
  if(gamma_v<0)return 0;

  return gamma_v;
}
Double_t VW_thetae(Double_t *x,Double_t *p){
  // Double_t E0=p[0];
  Double_t Mp=0.93821;
  Double_t W=x[0];//=W
  Double_t Eeprime=-(W*W-Mp*Mp-2*E0*Mp)/2/(2*E0*TMath::Sin(x[1]/2)*TMath::Sin(x[1]/2)+Mp);
  Double_t omega=E0-Eeprime;
  if(omega<0||omega>E0)return 0;
  Double_t Peprime=sqrt(Eeprime*Eeprime-0.511e-3*0.511e-3);
  Double_t Q2=4*E0*Eeprime*sin(x[1]/2)*sin(x[1]/2);//x[1]=thetae
  Double_t psi=TMath::ACos((Q2+2*E0*omega)/(2*E0*sqrt(Q2+omega*omega)));
  W=sqrt(Mp*Mp+2*Mp*omega-Q2);
  //cout<<"W "<<W<<" "<<x[0]<<" "<<Eeprime<<" "<<omega<<endl;
  if(W<0) return 0;
  else W=sqrt(W);
  eps=1./(1+2*(1+omega*omega/Q2)*TMath::Tan(x[1]/2)*TMath::Tan(x[1]/2));
  //Double_t eps=(1-1./(1+2*(1+omega*omega/Q2)*TMath::Tan(x[1]/2)*TMath::Tan(x[1]/2)))*TMath::Cos(x[1]);
  gamma_v=(1./137/2/TMath::Pi()*TMath::Pi())*(Eeprime/E0)*((W*W-Mp*Mp)/2/Mp)/Q2/(1-eps)*TMath::Sin(x[1]);//*TMath::Sin(psi);
  //if(gamma_v<0)cout<<omega<<" x[1] "<<x[1]<<" Eeprime "<<Eeprime<<" Peprime "<<Peprime<<" Q2 "<<Q2<<" psi "<<psi<<" W "<<W<<" eps "<<eps<<" gamma_v "<<gamma_v<<endl;
  if(gamma_v<0)return 0;
  return gamma_v;
}
Double_t VE0_W_thetae(Double_t *x,Double_t *p){
  Double_t E0=x[2];
  Double_t Mp=0.93821;
  Double_t W=x[0];//=W
  Double_t Eeprime=-(W*W-Mp*Mp-2*E0*Mp)/2/(2*E0*TMath::Sin(x[1]/2)*TMath::Sin(x[1]/2)+Mp);
  Double_t omega=E0-Eeprime;
  if(omega<0||omega>E0)return 0;
  Double_t Peprime=sqrt(Eeprime*Eeprime-0.511e-3*0.511e-3);
  Double_t Q2=4*E0*Eeprime*sin(x[1]/2)*sin(x[1]/2);//x[1]=thetae
  Double_t psi=TMath::ACos((Q2+2*E0*omega)/(2*E0*sqrt(Q2+omega*omega)));
  Double_t W=sqrt(Mp*Mp+2*Mp*omega-Q2);
  // ep->SetE(Eeprime);
  //ep->SetRho(Peprime);
  //ep->SetTheta(x[1]);
  //*gamma=*e0-*ep;
  //cout<<"theta g "<<psi<<" "<< gamma->Theta()<<endl;
  //cout<<"W "<<W<<" "<<x[0]<<" "<<Eeprime<<" "<<omega<<endl;
  if(W<0) return 0;
  else W=sqrt(W);
  eps=1./(1+2*(1+omega*omega/Q2)*TMath::Tan(x[1]/2)*TMath::Tan(x[1]/2));
  //Double_t eps=(1-1./(1+2*(1+omega*omega/Q2)*TMath::Tan(x[1]/2)*TMath::Tan(x[1]/2)))*TMath::Cos(x[1]);
  gamma_v=(1./137/2/TMath::Pi()*TMath::Pi())*(Eeprime/E0)*((W*W-Mp*Mp)/2/Mp)/Q2/(1-eps)*TMath::Sin(x[1]);//*TMath::Sin(psi);
  //if(gamma_v<0)cout<<omega<<" x[1] "<<x[1]<<" Eeprime "<<Eeprime<<" Peprime "<<Peprime<<" Q2 "<<Q2<<" psi "<<psi<<" W "<<W<<" eps "<<eps<<" gamma_v "<<gamma_v<<endl;
  if(gamma_v<0)return 0;
  return gamma_v;
}
TF2 *fflux=NULL;
TF1 *fflux1=NULL;
void VPhotonFlux(){
  //photon flux as function of omega and thetae'
  //  fflux=new TF2("fflux",&Vomega_thetae,0.5,10.5,1*TMath::DegToRad(),5*TMath::DegToRad(),0);
  //fflux=new TF2("fflux",&SigmaEe_thetae,0.5,10.9,2*TMath::DegToRad(),50*TMath::DegToRad(),0);
  fflux=new TF2("fflux",&SigmaEe_thetae,0.5,10.9,0.1,50,0);
  //    fflux=new TF2("fflux",&SigmaEe_thetae,0.5,10.5,0.5,15,0);
  fflux1=new TF1("fflux1",&VElastic_thetae,0,90,0);
  fflux->SetNpy(100);
  cout<<fflux->GetNpx()<<" "<<fflux->GetNpy()<<" "<<endl;
  //fflux=new TF3("fflux",&VE0_W_thetae,0.5,10.5,1*TMath::DegToRad(),9*TMath::DegToRad(),8,12,0);
  //fflux->SetParName(0,"E0");
  //fflux->SetParameter(0,11);
  return;
  TH2F* his2=new TH2F("his2","his2",1000,0.,10.5,1000,1*TMath::DegToRad(),5*TMath::DegToRad());
  TH1F* hisx=new TH1F("hisx","hisx",10000,0.,10.5);
  TH1F* hisy=new TH1F("hisy","hisy",10000,0,5);
  TH1F* hgth=new TH1F("hgth","hgth",10000,0,90);

  Double_t r1,r2;
  TBenchmark* bm=new TBenchmark();
  bm->Start("init");
  fflux->SetNpx(100);
  fflux->SetNpy(50);
  fflux->GetRandom2(r1,r2);
  bm->Stop("init");

  bm->Start("his100");
  for(Int_t i=0;i<100000;i++){
    fflux->GetRandom2(r1,r2);
    his2->Fill(r1,r2);
    hisx->Fill(r1);
    hisy->Fill(r2*TMath::RadToDeg());
    fflux->Eval(r1,r2);
    Double_t Eeprime=r1;
    Double_t thetae=r2;
    Double_t Q2=4*E0*Eeprime*sin(thetae/2)*sin(thetae/2);//x[1]=thetae
    Double_t omega=E0-Eeprime;
    Double_t psi=TMath::ACos((Q2+2*E0*omega)/(2*E0*sqrt(Q2+omega*omega)));
    hgth->Fill(psi*TMath::RadToDeg());
  }
  bm->Stop("his100");
  cout<<"his100 "<<bm->GetCpuTime("his100")<<" real "<<bm->GetRealTime("his100")
<<endl;
  cout<<"init "<<bm->GetCpuTime("init")<<" real "<<bm->GetRealTime("init")
<<endl;


}
//Rate in Hz, when using SigmaE_thetae
//fflux->Integral(0.5,4,2*TMath::DegToRad(),5*TMath::DegToRad())*1E35*1E-30*2*TMath::Pi()*TMath::DegToRad();//in degrees
//fflux->Integral(0.5,4,2*TMath::DegToRad(),5*TMath::DegToRad())*1E35
//fflux->Integral(0.5,4,2*TMath::DegToRad(),5*TMath::DegToRad())*1E35*(TMath::Sin(5*TMath::DegToRad())-TMath::Sin(2*TMath::DegToRad()))
