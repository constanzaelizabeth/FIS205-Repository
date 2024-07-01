#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <random>
#include <tuple>
#include <ctime>
#include <TCanvas.h>
#include <TH2F.h>
#include <TEllipse.h>
#include <TStyle.h>
#include <TFile.h>
#include <TTree.h>

using namespace std;

// Estructura para representar una partícula
struct Particle {
    double px, py, pz, E;
    double eta, phi, pt;

    // Constructor para inicializar una partícula
    Particle(double pt, double eta, double phi)
        : pt(pt), eta(eta), phi(phi) {
        px = pt * cos(phi);
        py = pt * sin(phi);
        pz = pt * sinh(eta);
        E = sqrt(px * px + py * py + pz * pz); // Calcular energía E
    }
};

// Función para calcular la distancia eta-phi entre dos partículas
double deltaR(double eta1, double phi1, double eta2, double phi2) {
    double deta = fabs(eta1 - eta2); // Diferencia en eta
    double dphi = fabs(phi1 - phi2); // Diferencia en phi
    if (dphi > M_PI) dphi = 2 * M_PI - dphi; // Ajustar dphi si es mayor que pi
    return sqrt(deta * deta + dphi * dphi); // Calcular distancia deltaR
}

// Algoritmo de agrupamiento Anti-Kt
vector<Particle> AntiKtClustering(const vector<Particle>& particles, double R) {
    vector<Particle> jets; // Vector para almacenar los jets resultantes
    vector<bool> clustered(particles.size(), false); // Vector para marcar partículas ya agrupadas
    const int k = -1; // Ajuste para el parámetro k en el algoritmo Anti-Kt

    vector<Particle> particles_copy = particles; // Hacer una copia de las partículas

    while (true) {
        vector<tuple<double, int, int>> distances; // Vector para almacenar distancias

        // Calcular distancias entre partículas
        for (size_t i = 0; i < particles_copy.size(); ++i) {
            if (clustered[i]) continue;

            double diB = pow(particles_copy[i].pt, 2 * k); // Calcula distancia diB
            distances.emplace_back(diB, i, -1); // Añadir distancia al vector

            for (size_t j = i + 1; j < particles_copy.size(); ++j) {
                if (clustered[j]) continue;

                double dR = deltaR(particles_copy[i].eta, particles_copy[i].phi, particles_copy[j].eta, particles_copy[j].phi); // Calcular distancia dR
                double dij = min(pow(particles_copy[i].pt, 2 * k), pow(particles_copy[j].pt, 2 * k)) * (dR * dR / (R * R)); // Calcular distancia dij
                distances.emplace_back(dij, i, j); // Añadir distancia al vector
            }
        }

        if (distances.empty()) break; // Terminar si no hay distancias

        sort(distances.begin(), distances.end()); // Ordenar distancias

        // Procesar la distancia mínima
        double min_dist = get<0>(distances[0]);
        int i = get<1>(distances[0]);
        int j = get<2>(distances[0]);

        if (j == -1) {
            // Eliminar partícula
            jets.push_back(particles_copy[i]); // Añadir partícula al jet
            clustered[i] = true; // Marcar partícula como agrupada
        } else {
            // Combinar partículas
            double pt_new = particles_copy[i].pt + particles_copy[j].pt; // Calcular nuevo pt
            double eta_new = (particles_copy[i].eta * particles_copy[i].pt + particles_copy[j].eta * particles_copy[j].pt) / pt_new; // Calcular nuevo eta
            double phi_new = (particles_copy[i].phi * particles_copy[i].pt + particles_copy[j].phi * particles_copy[j].pt) / pt_new; // Calcular nuevo phi
            Particle new_particle(pt_new, eta_new, phi_new); // Crear nueva partícula combinada
            particles_copy[i] = new_particle; // Reemplazar partícula i con la nueva partícula
            clustered[j] = true; // Marcar partícula j como agrupada
        }
    }

    return jets; // Devolver los jets
}

// Función para el Anti-Kt clustering
void antiKtClustering() {
    vector<double> pt, eta, phi, E;
    vector<double> jet_pt, jet_eta, jet_phi, jet_E;

    const int nParticles = 2000; // Número de partículas
    const double mean_pt = 50.0; // Valor medio de pt
    const double std_pt = 10.0; // Desviación estándar de pt
    const double mean_eta = 0.0; // Valor medio de eta
    const double std_eta = 1.0; // Desviación estándar de eta

    random_device rd;
    mt19937 gen(rd());
    normal_distribution<> d_pt(mean_pt, std_pt); // Distribución normal para pt
    normal_distribution<> d_eta(mean_eta, std_eta); // Distribución normal para eta
    uniform_real_distribution<> d_phi(-M_PI, M_PI); // Distribución uniforme para phi

    vector<Particle> particles; //Vector que almacena partículas
    for (int i = 0; i < nParticles; ++i) {
        particles.emplace_back(d_pt(gen), d_eta(gen), d_phi(gen)); //Genera partículas aleatorias
    }

    for (const auto& P : particles) {
        pt.push_back(P.pt);
        eta.push_back(P.eta);
        phi.push_back(P.phi);
        E.push_back(P.E);
    }

    // Realiza el agrupamiento
    double R = 0.6; // Radio de agrupamiento
    vector<Particle> jets = AntiKtClustering(particles, R);

    for (const auto& jet : jets) {
        // Almacena los datos
        jet_pt.push_back(jet.pt);
        jet_eta.push_back(jet.eta);
        jet_phi.push_back(jet.phi);
        jet_E.push_back(jet.E); 
    }

    // Rellena el árbol
    TFile* file = TFile::Open("antiKtSimulation0.root", "RECREATE");
    TTree* tree = new TTree("tree", "Anti-Kt Clustering Tree");

    tree->Branch("pt", &pt);
    tree->Branch("eta", &eta);
    tree->Branch("phi", &phi);
    tree->Branch("E", &E);
    tree->Branch("jet_pt", &jet_pt);
    tree->Branch("jet_eta", &jet_eta);
    tree->Branch("jet_phi", &jet_phi);
    tree->Branch("jet_E", &jet_E);

    tree->Fill();

    //Se guarda el archivo ROOT y se limpia la memoria
    tree->Write();
    file->Close();

    delete tree;
    delete file;
}


int main() {
    antiKtClustering(); // Llamar a la función de agrupamiento Anti-Kt
    cout << "El archivo antiKtSimulation.root ha sido creado y el gráfico ha sido guardado como antiKtClustering.png" << endl;
    return 0;
}
