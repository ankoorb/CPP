import os
import random
import numpy as np
from collections import defaultdict

class SyntheticData:
    
    _alphas = ["A", "B", "C", "D", "E", "F", "G", "H", "I", "J"]
    _mu_sigma = [(10000.0, 2500.0), (20000.0, 5000.0), (30000.0, 10000.0), (40000.0, 15000.0), 
                 (50000.0, 20000.0), (60000.0, 25000.0), (70000.0, 30000.0), (80000.0, 35000.0)]
    
    def __init__(self, galaxy, star, planet, star_choice_size=1000, planet_choice_size=10000):
        self.galaxies = galaxy
        random.shuffle(self.galaxies)
        self.star = star
        self.planet = planet
        self.star_choice_size = star_choice_size
        self.planet_choice_size = planet_choice_size
        self.galaxies_size = len(self.galaxies)
        self.mu_sigma_size = len(SyntheticData._mu_sigma)
        self.data = []
        self.galaxy_mu_sigma = defaultdict(list)
        self.galaxy_stars = defaultdict(list)
        self.star_mu_sigma = defaultdict(list)
        self.star_planets = defaultdict(list)
        self.generateData()
        
        
    def process(self):
        _stars = np.random.choice(self.star, self.star_choice_size)
        _alphas = np.random.choice(SyntheticData._alphas, self.star_choice_size)
        self.stars = list(set([s + "_" + a for s, a in zip(_stars, _alphas)]))
        random.shuffle(self.stars)
        self.stars_size = len(self.stars)
        
        _planets = np.random.choice(self.planet, self.planet_choice_size)
        _digits = list(np.random.randint(111, high=1000, size=self.planet_choice_size))
        self.planets = list(set([p + str(d) for p, d in zip(_planets, _digits)]))
        random.shuffle(self.planets)
        self.planets_size = len(self.planets)
        
        
    def galaxyData(self):
        for galaxy in self.galaxies:
            idx = np.random.randint(0, self.mu_sigma_size)
            mu, sigma = SyntheticData._mu_sigma[idx]
            self.galaxy_mu_sigma[galaxy].append((mu, sigma))
            coord = np.random.normal(loc=mu, scale=sigma, size=2)
            x = round(coord[0], 2)
            y = round(coord[1], 2)
            text = "Galaxy|" + galaxy + '|' + str(x) + '|' + str(y) + "|Universe|"
            self.data.append(text)
            
            
    def starData(self):
        window = (self.stars_size // self.galaxies_size)
        
        i = 0
        j = 0
        idx = 0
        while i < self.stars_size and idx < self.galaxies_size:
            galaxy_stars = self.stars[j:j+window]
            for star in galaxy_stars:
                self.galaxy_stars[self.galaxies[idx]].append(star)
            i += window
            j = i
            idx += 1
            
        galaxy_stars = self.stars[j:]
        for i in range(len(galaxy_stars)):
            self.galaxy_stars[self.galaxies[i % self.galaxies_size]].append(galaxy_stars[i])
            
        for galaxy in self.galaxies:
            stars = self.galaxy_stars[galaxy]
            mu, sigma = self.galaxy_mu_sigma[galaxy][0]
            for star in stars:
                self.star_mu_sigma[star].append((mu, sigma))
                coord = np.random.normal(loc=mu, scale=sigma, size=2)
                x = round(coord[0], 2)
                y = round(coord[1], 2)
                text = "Star|" + star + '|' + str(x) + '|' + str(y) + '|' + galaxy + '|'
                self.data.append(text)
                
                            
    def planetData(self):
        window = (self.planets_size // self.stars_size)
        
        i = 0
        j = 0
        idx = 0
        while i < self.planets_size and idx < self.stars_size:
            star_planets = self.planets[j:j+window]
            for planet in star_planets:
                self.star_planets[self.stars[idx]].append(planet)
            i += window
            j = i
            idx += 1
            
        star_planets = self.planets[j:]
        for i in range(len(star_planets)):
            self.star_planets[self.stars[i % self.stars_size]].append(star_planets[i])
            
        for star in self.stars:
            planets = self.star_planets[star]
            mu, sigma = self.star_mu_sigma[star][0]
            for planet in planets:
                coord = np.random.normal(loc=mu, scale=sigma, size=2)
                x = round(coord[0], 2)
                y = round(coord[1], 2)
                text = "Planet|" + planet + '|' + str(x) + '|' + str(y) + '|' + star + '|'
                self.data.append(text)
                
                            
    def generateData(self):
        self.process()
        self.galaxyData()
        self.starData()
        self.planetData()
        random.shuffle(self.data)
        
        
    def writeFile(self, path=None):
        if path == None:
            path = os.getcwd() 
            
        path += "/synthetic.txt"
        
        with open(path, 'w') as f:
            for line in self.data:
                f.write(line + "\n")

        print("Synthetic data file is created at: {}".format(path))
                
                
if __name__ == "__main__":
    
    galaxy = [
        "Andromeda", "Antlia", "Caelum", "Cassiopeia", "Draco", "Dorado", "Eridanus", 
        "Hydra", "Lynx", "Mensa", "Norma", "Orion", "Pegasus", "Perseus", "Reticulum", 
        "Sagitta", "Serpens", "Tigris", "Ursa", "Volans", "Winterfell", "Zephyr"
        ]

    star = [
        "Alpha", "Beta", "Gamma", "Delta", "Epsilon", "Zeta", "Eta", "Theta", "Iota", "Kappa", "Lambda", 
        "Omicorn", "Rho", "Sigma", "Tau", "Upsilon", "Phi", "Chi", "Psi", "Omega", "Mu", "Nu", "Xi"
        ]

    planet = [
        "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", 
        "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"
        ]

    synthetic_data = SyntheticData(galaxy, star, planet)
    synthetic_data.writeFile()
