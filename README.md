# **Ventilator Controlat de la distanță cu Telecomandă IR, Arduino**  
---

## **Descriere Proiect**  
Acest proiect permite controlul automat al unui ventilator folosind o placă **Arduino Mega 2560**, un senzor de temperatură **DHT11** și o telecomandă **IR**. Temperatura setată poate fi ajustată prin telecomandă, iar valorile sunt afișate pe un ecran **LCD**. De asemenea am folosit o **punte H** pentru a opri/porni ventilatorul.

---

## **Componente Folosite**  
| **Componentă** | **Descriere** |
|---------------|---------------|
| **Arduino Uno** | Placă de control principală |
| **Senzor DHT11** | Măsoară temperatura |
| **Punte H** | Controlează ventilatorul (pornire/oprire și direcție) |
| **Receptor IR** | Primește comenzi de la telecomandă |
| **LCD cu I2C** | Afișează temperatura curentă și cea setată |
| **Ventilator** | Controlat prin puntea H |

---

## **Funcționare**  
1. Senzorul **DHT11** măsoară temperatura.  
2. Dacă temperatura curentă depășește temperatura setată, **ventilatorul pornește automat**.  
3. Temperatura dorită poate fi ajustată folosind o **telecomandă IR** (butoanele sus și jos).  
4. Datele sunt afișate pe un ecran **LCD**:  
   - **Temperatura curentă**  
   - **Temperatura dorită**  

---

##  **Schema de conectare**  
![image](https://github.com/user-attachments/assets/c5375bc7-06e2-41fb-ae21-175a904850db)


---
